/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #5
    @file quickSort.cpp
    @author Taiyr Begeyev
    @version 1.0 15/03/19
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
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Lomuto Quick Sort
template <typename T>
void LomutoQuickSort(vector<T> &arr, int start, int end);
template <typename T>
int LomutoPartition(vector<T> &arr, int start, int end);

// Hoare Quick Sort
template <typename T>
void HoareQuickSort(vector<T> &arr, int start, int end);
template <typename T>
int HoarePartition(vector<T> &arr, int start, int end);

// Median of three
template <typename T>
void Median3QuickSort(vector<T> &arr, int start, int end);
template <typename T>
int median3(vector<T> &arr, int start, int end);
template <typename T>
int Median3Partition(vector<T> &arr, int start, int end, T pivot);

const int SEQUENCES = 100000;
const int LENGTH = 1000;

void printArr(vector<int> arr) {
    for (int i = 0; i < LENGTH; i++) 
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    // OPEN FILE
    ofstream out;
    out.open("output.dat", ios::trunc | ios::out);
    if (!out.is_open()) {
        cerr << "Something went wrong. Coudln't open the file" << endl;
        exit(1);
    }

    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;

    double average1 = 0, average2 = 0, average3 = 0;     

    for (int i = 0; i < SEQUENCES; i++) {
        for (int j = 0; j < LENGTH; j++) {
            arr1.push_back(rand() % (LENGTH * 10) + 1);
        }
        out << i << " ";
        arr2 = arr1;
        arr3 = arr1;

        cout << "Initial array:" << endl;
        printArr(arr1);

        cout << "Sorted arrays: " << endl;

        // test Lomuro Quick Sort
        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        LomutoQuickSort<int>(arr1, 0, LENGTH - 1);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        double duration = duration_cast<microseconds>(t2 - t1).count();
        out << duration << " ";
        average1 += duration;
        printArr(arr1);

        // test Hoare Quick Sort
        t1 = high_resolution_clock::now();
        HoareQuickSort<int>(arr2, 0, LENGTH - 1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>(t2 - t1).count();
        out << duration << " ";
        average2 += duration;
        printArr(arr2);

        // test Median of Three
        t1 = high_resolution_clock::now();
        Median3QuickSort<int>(arr3, 0, LENGTH - 1);
        t2 = high_resolution_clock::now();
        duration = duration_cast<microseconds>(t2 - t1).count();
        out << duration << endl;
        average3 += duration;
        printArr(arr3);
        cout << endl;
        cout << endl;

        arr1.clear();
        arr2.clear();
        arr3.clear();
    }
    cout << endl;
    cout << "Average for Lomuro: " << average1 / SEQUENCES << endl;
    cout << "Average for Hoare: " << average2 / SEQUENCES << endl;
    cout << "Average for Median of Three: " << average3 / SEQUENCES << endl;

    out.close();
    return 0;
}

/**
 * @brief implementation of the Quick Sort Algorithm
 * @param arr[] array which is needed to be sorted
 * @param start - index we need to start sorting with
 * @param end - index we need to stop sorting at 
*/
template <typename T>
void LomutoQuickSort(vector<T> &arr, int start, int end) {
    // base case
    if (start < end) {
        int q = LomutoPartition(arr, start, end);
        LomutoQuickSort(arr, start, q - 1);
        LomutoQuickSort(arr, q + 1, end); 
    }
}

/**
 *  @brief key to the Quick Sort Algorithm
 *  
 *  Always selects an the front element as a pivot (our case)
 *  element around which to partition subarray A[start .. end]
 *  @param arr[] array which is needed to be sorted
 *  @param start - index we need to start sorting with
 *  @param end - index we need to stop sorting at 
*/
template <typename T>
int LomutoPartition(vector<T> &arr, int start, int end) {
    // make the most left hand element a pivot 
    T pivot = arr[start];    
    int pivotIndex = start;

    for (int j = start + 1; j <= end; j++) {
        // iterate through all list starting from the 
        // element next to the 'start' 
        if (arr[j] < pivot) {
            pivotIndex++;
            swap(arr[j], arr[pivotIndex]);
        }
    }

    // after we located all elements which are <= than 
    // the pivot put the pivot on its supposed place
    swap(arr[start], arr[pivotIndex]);
    return pivotIndex;
}

/**
 * @brief implementation of the Quick Sort Algorithm
 * @param arr[] array which is needed to be sorted
 * @param start - index we need to start sorting with
 * @param end - index we need to stop sorting at 
*/
template <typename T>
void HoareQuickSort(vector<T> &arr, int start, int end) {
    // base case
    if (start < end) {
        int q = HoarePartition(arr, start, end);
        HoareQuickSort(arr, start, q);
        HoareQuickSort(arr, q + 1, end); 
    }
}

/**
 * @brief works by initializing two indexes that start 
 * at two ends, the two indexes move toward each other 
 * until an inversion is (A smaller value on left side 
 * and greater value on right side) found. When an 
 * inversion is found, two values are swapped and process 
 * is repeated. 
 * 
*/
template <typename T>
int HoarePartition(vector<T> &arr, int start, int end) {
    T pivot = arr[start];
    int i = start - 1; // initialize the left index
    int j = end + 1; // initialize the right index

    while(1) {
        do {
            // find leftmost element greater than or
            // equal to pivot
            i++;
        } while(arr[i] < pivot);

        do {
            // find rightmost element less than or 
            // equal to pivot
            j--;
        } while(arr[j] > pivot);

        if (i >= j)
            // if two ponters met
            return j;
        
        swap(arr[i], arr[j]);
    }
}

/**
 * @brief implementation of the Quick Sort Algorithm
 * @param arr[] array which is needed to be sorted
 * @param start - index we need to start sorting with
 * @param end - index we need to stop sorting at 
*/
template <typename T>
void Median3QuickSort(vector<T> &arr, int start, int end) {
    // base case
    if (start < end) {
        T pivot = median3(arr, start, end);
        // begin partitioning
        int i;
        i = Median3Partition(arr, start, end, pivot);
        Median3QuickSort(arr, start, i);
        Median3QuickSort(arr, i + 1, end);
    }
}

/**
 * @brief Median of three
 * 
 * Compare three elements: the leftmost, rightmost 
 * and center. Swap these elements if necessary so 
 * that 
 *      A[left] = smallest
 *      A[right] = largest
 *      A[center] = median of three
 * Pick A[center as the pivot]
 * Swap A[center] and A[right - 1] so that pivot is at
 * second last position
 * 
*/
template <typename T>
int median3(vector<T> &arr, int start, int end) {
    int center = (start + end) / 2;
    if (arr[center] < arr[start])
        swap(arr[start], arr[center]);
    if (arr[end] < arr[start])
        swap(arr[start], arr[end]);
    if (arr[end] < arr[center])
        swap(arr[center], arr[end]);

    // place a pivot at position end - 1
    swap(arr[center], arr[end - 1]);
    return center;
}

/**
 * @brief works by initializing two indexes that start 
 * at two ends, the two indexes move toward each other 
 * until an inversion is (A smaller value on left side 
 * and greater value on right side) found. When an 
 * inversion is found, two values are swapped and process 
 * is repeated. 
 * 
*/
template <typename T>
int Median3Partition(vector<T> &arr, int start, int end, T pivot) {
    pivot = arr[start];
    int i = start - 1; // initialize the left index
    int j = end + 1; // initialize the right index

    while(1) {
        do {
            // find leftmost element greater than or
            // equal to pivot
            i++;
        } while(arr[i] < pivot);

        do {
            // find rightmost element less than or 
            // equal to pivot
            j--;
        } while(arr[j] > pivot);

        if (i >= j)
            // if two ponters met
            return j;
        
        swap(arr[i], arr[j]);
    }
    return arr[start];
}