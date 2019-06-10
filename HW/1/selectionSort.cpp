/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #1
    selectionSort.cpp
    Purpose: Implementation of the Selection Sort Algorithm

    @author Taiyr Begeyev
    @version 1.0 13/02/19
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int* generateArrayOfRandomNumbers (int* arr_local, int n);
int* selectionSort(int* arr_local, int length);
int* reverseOrderOfArray(int* arr_local, int length);
int* copyArray(int* arr1, int* arr2, int length);
void printArray(int* arr_local, int length);

int main() {
    srand(time(NULL));
    clock_t t1, t2, t3;

    //generating random number from 1..20
    int randomNumberOfElements = rand() % 10 + 1;

    //Dynamic array allocation
    int* arr = NULL;
    int* arrBestCase = NULL;
    int* arrWorstCase = NULL;
    arr = new int[randomNumberOfElements]; //average case
    arrBestCase = new int[randomNumberOfElements];
    arrWorstCase = new int[randomNumberOfElements];

    cout << "Number of elements: " << randomNumberOfElements << endl;
    arr = generateArrayOfRandomNumbers(arr, randomNumberOfElements);
    cout << "Generated array: " << endl;
    printArray(arr, randomNumberOfElements);

    //copy elements from arr1 to arr2
    arrBestCase = copyArray(arr, arrBestCase, randomNumberOfElements);
    arrWorstCase = copyArray(arr, arrWorstCase, randomNumberOfElements);
    
    // in best case array is already sorted
    // in worst case array is reversed
    //we use corresponding functions
    arrBestCase = selectionSort(arrBestCase, randomNumberOfElements);
    arrWorstCase = reverseOrderOfArray(arrWorstCase, randomNumberOfElements);

    cout << endl;
    cout << "The array out of generated (average case): " << endl;
    printArray(arr, randomNumberOfElements);

    // -------------------------------- 
    // COMPUTATION TIME OF AVERAGE CASE
    t1 = clock();
    arr = selectionSort(arr, randomNumberOfElements);
    cout << "Sorted array: " << endl;
    printArray(arr, randomNumberOfElements);

    t1 = clock() - t1;
    //Stop measuring time here
    double duration1 = double(t1) / CLOCKS_PER_SEC;
    cout << endl;
    // ---------------------------------

    cout << "The array out of generated (best case): " << endl;
    printArray(arrBestCase, randomNumberOfElements);

    // -------------------------------- 
    // COMPUTATION TIME OF BEST CASE
    t2 = clock();
    arrBestCase = selectionSort(arrBestCase, randomNumberOfElements);
    cout << "Sorted array: " << endl;
    printArray(arrBestCase, randomNumberOfElements);

    t2 = clock() - t2;
    //Stop measuring time here
    double duration2 = double(t2) / CLOCKS_PER_SEC;
    cout << endl;
    // ---------------------------------

    cout << "The array out of generated (worst case): " << endl;
    printArray(arrWorstCase, randomNumberOfElements);

    // -------------------------------- 
    // COMPUTATION TIME OF THE WORST CASE
    t3 = clock();
    arrWorstCase = selectionSort(arrWorstCase, randomNumberOfElements);
    cout << "Sorted array: " << endl;
    printArray(arrWorstCase, randomNumberOfElements);

    t3 = clock() - t3;
    //Stop measuring time here
    double duration3 = double(t3) / CLOCKS_PER_SEC;
    cout << endl;
    // ---------------------------------

    /*
        Execution times
    */
    cout << "Execution time for worst case: "<< fixed << duration3 << endl;
    cout << "Execution time for average case: "<< fixed << duration1 << endl;
    cout << "Execution time for best case: "<< fixed << duration2 << endl;

    delete [] arr;
    delete [] arrWorstCase;
    delete [] arrBestCase;
    arr = NULL;
    arrWorstCase = NULL;
    arrBestCase = NULL;
    return 0;
}

/*
    @brief generates array of random numbers in a certain range
    @param array and its length
    @returns randomized array
*/

int* generateArrayOfRandomNumbers (int* arr_local, int n) {
    for(int i = 0; i < n; i++) {
        arr_local[i] = rand() % 200 + 1;
    }
    return arr_local;
}

/*
    @brief implementation of the Selection Sort Algorithm
        At every step, algorithm finds minimal element in the unsorted part and 
        adds it to the end of the sorted one. 
        When unsorted part becomes empty, algorithm stops.
    @param array and its length
    @returns sorted array
*/

int* selectionSort(int* arr_local, int length) {
    int positionOfMin, tmp;

    //go through all elements
    for (int i = 0; i < length - 1; i++) {
        //make current element min and remember its position
        positionOfMin = i;
        //find tshe min in unsorted part
        for (int j = i + 1; j < length; j++) {
            if (arr_local[j] < arr_local[positionOfMin]) {
                positionOfMin = j;
            }
        }

        //swap min with current element if min is not current element
        if (positionOfMin != i) {
            tmp = arr_local[i];
            arr_local[i] = arr_local[positionOfMin];        
            arr_local[positionOfMin] = tmp;
        }
    } 
    return arr_local;
}

/*
    @brief make a reversed order of an array for the worst case 
    @param array and its length
    @returns reversed array
*/

int* reverseOrderOfArray(int* arr_local, int length) {
    int positionOfMax, tmp;

    //go through all elements
    for (int i = 0; i < length - 1; i++) {
        //make current element min and remember its position
        positionOfMax = i;
        //find tshe min in unsorted part
        for (int j = i + 1; j < length; j++) {
            if (arr_local[j] > arr_local[positionOfMax]) {
                positionOfMax = j;
            }
        }

        //swap min with current element if min is not current element
        if (positionOfMax != i) {
            tmp = arr_local[i];
            arr_local[i] = arr_local[positionOfMax];        
            arr_local[positionOfMax] = tmp;
        }
    } 
    return arr_local;
}

/*
    @brief copies elements from Arr1 to Arr 2
    @param arr1
    @param arr2
    @param length of both arrays
    @returns the array where elements from arr1 were copied to
*/

int* copyArray(int* arr1, int* arr2, int length) {
    for (int i = 0; i < length; i++) {
        arr2[i] = arr1[i];
    } 
    return arr2;
}

/*
    @brief prints all elements of the array 
    @param array and its length 
*/

void printArray(int* arr_local, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr_local[i] << " ";
    }
    cout << endl;
}