 /*
    Algorithms and Data Structures
    Spring 2019
    Assignment #2
    mergeSort.cpp

    Purpose:  Implement a variant of Merge Sort that does not divide the problem all the way 
    down to subproblems of size 1. Instead, when reaching subsequences of length k it applies
    Insertion Sort on these n/k subsequences.

    @author Taiyr Begeyev
    @version 2.0 20/02/19
*/

/*
__________          .__                   
\__    ___/ _____    |__|  ___.__. _______ 
  |    |    \__  \   |  | <   |  | \_  __ \
  |    |     / __ \_ |  |  \___  |  |  | \/
  |____|    (____  / |__|  / ____|  |__|   
                \/        \/              
*/
 
 

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

/* Prototype Declaration */
//void insertionSort(int arr[], int length);
void insertionSort(int arr[], int min, int max);
void merge(int arr[], int start, int middle, int end);
void mergeSort(int arr[], int start, int end, int k);
void printArr(int arr[], int length);
void randomlyGenerateArray(int arr[], int length);
void copyArray(int arr1[], int arr2[], int length);
void reverseOrderOfArray(int arr[], int length);
void differentNforTheSameK(string name, int k);

int main() {
    /* basic setup */
    ofstream myfile1;
    myfile1.open("output1.dat");
    srand(time(NULL));

    int length = rand() % 100 + 1; 
    int* arr = new int[length]; //main array
    int* arrAverageCase = new int[length];
    int* arrBestCase = new int[length];
    int* arrWorstCase = new int[length]; 

    randomlyGenerateArray(arr, length);
    //copy arr to another arrays 
    copyArray(arr, arrAverageCase, length);
    copyArray(arr, arrBestCase, length);
    copyArray(arr, arrWorstCase, length);

    // Worst Case
    // reversed order 
    reverseOrderOfArray(arrWorstCase, length);

    //Best Case
    // already sorted array
    insertionSort(arrBestCase, 0, length - 1);
    
    cout << "Length of the array: " << length << endl;
    cout << "Array: " << endl;
    printArr(arr, length);
    cout << endl;

    cout << "Sorted array: " << endl;
    printArr(arrBestCase, length);
    cout << endl;

    // ------------------------------------------------------------------
    // CHECK THE SAME ARRAY FOR DIFFERENT k AND FOR DIFFERENT SCENARIOS
    // (AVERAGE CASE, WORST CASE, BEST CASE) 
    // write k and the corresponding time to output1.dat
    for (int k = 1; k <= length; k++) {
        //WORST CASE
        //start measuring time
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        mergeSort(arrWorstCase, 0, length - 1, k);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        // finish 
        //convert to microseconds
        auto duration = duration_cast<microseconds>( t2 - t1 ).count();
        //write data to the file output.dat
        myfile1 << k << " " << duration << " ";

        //AVERAGE CASE
        //start measuring time
        t1 = high_resolution_clock::now();
        mergeSort(arrAverageCase, 0, length - 1, k);
        t2 = high_resolution_clock::now();
        // finish 
        //convert to microseconds
        duration = duration_cast<microseconds>( t2 - t1 ).count();
        //write data to the file output.dat
        myfile1 << k << " " << duration << " ";

        //BEST CASE
        //start measuring time
        t1 = high_resolution_clock::now();
        mergeSort(arrBestCase, 0, length - 1, k);
        t2 = high_resolution_clock::now();
        // finish 
        //convert to microseconds
        duration = duration_cast<microseconds>( t2 - t1 ).count();
        //write data to the file output.dat
        myfile1 << k << " " << duration << endl;

        //Since we modified our arrays (sorted it), we need to get the initial sequence
        // that's why we copy arr to them 
        copyArray(arr, arrAverageCase, length);
        copyArray(arr, arrWorstCase, length);
    }

    delete[] arr;
    delete[] arrAverageCase;
    delete[] arrWorstCase;
    delete[] arrBestCase;

    // ------------------------------------------------------------------
    // CHECK DIFFERENT ARRAYS FOR THE SAME k AND FOR DIFFERENT SCENARIOS
    // (AVERAGE CASE, WORST CASE, BEST CASE)
    // write n size and the corresponding time to output2.dat and output3.dat
    
    //We will check different arrays for two different k
    // FIRST 
    //k = 20;
    differentNforTheSameK("output2.dat", 20);    
    // SECOND
    // k = 50;
    differentNforTheSameK("output3.dat", 50);
    
    myfile1.close();
    return 0;
}

/*
    @brief 
        Implementation of Insertion Sort Algorithm. 
        The array is searched sequentially
        and unsorted items are moved and inserted into the sorted sub-list 
    @param array
    @param lenght of the array
*/

void insertionSort(int arr[], int min, int max) {
    int key, j;
    for (int i = min + 1; i <= max; i++) {
        key = arr[i];
        j = i - 1;

        while(j >= min && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; 
    }
}

/*
    @brief
        Create two arrays(left and right). Find the length of them and 
        copy the values from arr to them. Merge them 
    @param array
    @param start index
    @param middle index
    @param end index
*/

void merge(int arr[], int start, int middle, int end) {
    int i, j, k;

    //find the length of the Left Hand array
    int lengthOfLeft = middle - start + 1;
    //find the length of the Right Hand array
    int lengthOfRight = end - middle;

    //create two arrays
    int left[lengthOfLeft], right[lengthOfRight];

    //fill two arrays with elements from arr
    for (i = 0; i < lengthOfLeft; i++) 
        left[i] = arr[start + i];
    for (j = 0; j < lengthOfRight; j++)
        right[j] = arr[middle + 1 + j];

    i = 0; j = 0; k = start;
    while(i < lengthOfLeft && j < lengthOfRight) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }


    /* Copy the remaining elements of L[], if there 
       are any */
    while(i < lengthOfLeft) {
        arr[k] = left[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while(j < lengthOfRight) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

/*
    @brief
        Sorts the elements in the subarray A[start..end]. If start >= end, the 
        subarray has at most one element and is therefore already sorted.
        Otherwise, the divide step simply computes an index middle that
        partitions A[start..end] into two subarrays: A[start..middle] and
        A[middle + 1 .. end]

        To sort the entire sequence, we make initial call, where start = 0
        and end = A.length 
    @param array
    @param starting index
    @param ending index
    @param length of a certain subsequence
*/

void mergeSort(int arr[], int start, int end, int k) {
    if (end - start + 1 <= k) {
        insertionSort(arr, start, end);        
    } 
    else {
        int middle = (end + start) / 2;
        mergeSort(arr, start, middle, k);
        mergeSort(arr, middle + 1, end, k);
        merge(arr, start, middle, end);
    }
}

/*
    @brief print an array
    @param array
    @param a length of the array
*/

void printArr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
    @brief generates array of random numbers in a certain range
    @param array and its length
    @returns randomized array
*/

void randomlyGenerateArray(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 500 + 1;
    }
}

/*
    @brief copies elements from Arr1 to Arr 2
    @param arr1
    @param arr2
    @param length of both arrays
    @returns the array where elements from arr1 were copied to
*/

void copyArray(int arr1[], int arr2[], int length) {
    for (int i = 0; i < length; i++) {
        arr2[i] = arr1[i];
    }
}

/*
    @brief make a reversed order of an array for the worst case 
    @param array and its length
    @returns reversed array
*/

void reverseOrderOfArray(int arr[], int length) {
    int positionOfMax, tmp;

    //go through all elements
    for (int i = 0; i < length - 1; i++) {
        //make current element min and remember its position
        positionOfMax = i;
        //find tshe min in unsorted part
        for (int j = i + 1; j < length; j++) {
            if (arr[j] > arr[positionOfMax]) {
                positionOfMax = j;
            }
        }

        //swap min with current element if min is not current element
        if (positionOfMax != i) {
            tmp = arr[i];
            arr[i] = arr[positionOfMax];        
            arr[positionOfMax] = tmp;
        }
    } 
}

/*
    @brief CHECK DIFFERENT ARRAYS FOR THE SAME k AND FOR DIFFERENT SCENARIOS
           (AVERAGE CASE, WORST CASE, BEST CASE)
           write n size and the corresponding time to output2.dat and output3.dat
           We will check different arrays for two different k
    @param the name of file we want to write data to
    @param k
*/

void differentNforTheSameK(string name, int k) {
    ofstream myfile;
    myfile.open(name);

    for (int i = 100; i < 1000; i += 10) {
        int* arr = new int[i]; //main array
        int* arrAverageCase = new int[i];
        int* arrBestCase = new int[i];
        int* arrWorstCase = new int[i]; 

        randomlyGenerateArray(arr, i);    
        copyArray(arr, arrAverageCase, i);
        copyArray(arr, arrBestCase, i);
        copyArray(arr, arrWorstCase, i);

        //WORST CASE
        //start measuring time
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        mergeSort(arrWorstCase, 0, i - 1, k);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        // finish 
        //convert to microseconds
        auto duration = duration_cast<microseconds>( t2 - t1 ).count();
        //write data to the file 
        myfile << i << " " << duration << " ";

        //AVERAGE CASE
        //start measuring time
        t1 = high_resolution_clock::now();
        mergeSort(arrAverageCase, 0, i - 1, k);
        t2 = high_resolution_clock::now();
        // finish 
        //convert to microseconds
        duration = duration_cast<microseconds>( t2 - t1 ).count();
        //write data to the file 
        myfile << i << " " << duration << " ";

        //BEST CASE
        //start measuring time
        t1 = high_resolution_clock::now();
        mergeSort(arrBestCase, 0, i - 1, k);
        t2 = high_resolution_clock::now();
        // finish 
        //convert to microseconds
        duration = duration_cast<microseconds>( t2 - t1 ).count();
        //write data to the file output.dat
        myfile << i << " " << duration << endl;

        delete[] arr;
        delete[] arrAverageCase;
        delete[] arrWorstCase;
        delete[] arrBestCase;
    }
    myfile.close();
}