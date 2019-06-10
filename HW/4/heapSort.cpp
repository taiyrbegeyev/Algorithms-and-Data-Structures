/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #4
    @file heapSort.cpp
    @author Taiyr Begeyev
    @version 1.0 08/03/19
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
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

// store the size of the heap
int heapSize;

// prototype declaration
void maxHeapify(vector<int>&, const int&);
void buildMaxHeap(vector<int>&);
void heapSort(vector<int>&);
void printArr(vector<int>&);
void heapSortModified(vector<int>& arr);
void newApproach(vector<int>&, const int&);

int main(){
    srand(time(NULL));
    int length = rand() % 20 + 1;
    cout << "Length: " << length << endl;
    vector<int> a(length);

    // assign random values to the elements of the array
    // in the range 1..100 
    for (int i = 0; i < length; i++) 
        a[i] = rand()% 100 + 1;

    heapSort(a);
    printArr(a);

    return 0;
}

/**
 * @brief bottom-way approach. floats the new root all the way down to a 
 * leaf level. Then, it checks whether that was actually correct and if
 * not fixes the max-heap by moving the element up again. 
 * 
 * @param arr the heap array
 * @param i the current root of the subtree
*/
void newApproach(vector<int>& arr, const int& i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = 0;
    if(left < heapSize && arr[left] > arr[largest])
        largest = left;
    if(right < heapSize && arr[right] > arr[largest])
        largest = right;

    if(largest == 0){
        swap(arr[0], arr[i]);
        return;
    }

    newApproach(arr, largest);
    swap(arr[0], arr[i]);
}

/**
 * @brief lets the value at arr[i] float down, so that subtree
 * rooted at index i obeys the max-heap property, where parent is
 * greater than any of its children 
 * 
 * @param array arr
 * @param i - index into the array
* */
void maxHeapify(vector<int>& arr, const int& i){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest;

    if (left < heapSize && arr[left] > arr[i])
        largest = left;
    else
        largest = i;

    if (right < heapSize && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest);
    }
}

/**
 * @brief in a bottom-up manner make the  arr[1..n] have the max 
 * heap property
 * 
 * @param arr
*/
void buildMaxHeap(vector<int>& arr){
    heapSize = arr.size();
    for (int i = (arr.size() / 2) - 1; i >= 0; i--) 
        maxHeapify(arr, i);
}

/**
 * @brief sorts the array
 *  
 * Start by using buildMaxHeap funnction to build a max-heap. Since 
 * the max element of the array is stored at the root, we can put it
 * into its correct position by exchaning it with arr[i]. If we now 
 * discard node n from the heap — and we can do so by simply decrementing 
 * heapSize — we observe that the children of the root remain max-heaps,
 * but the new root element might violate the max-heap property. 
 * All we need to do to restore the max-heap property, however, is call
 * maxHeapify(arr, i, 0). The heapsort algorithm then repeats this process 
 * for the max-heap of size n - 1 down to a heap of size 1 
 *  
 * @param arr
*/
void heapSort(vector<int>& arr){
    buildMaxHeap(arr);
    for (int i = heapSize - 1; i >= 1; i--) {
        swap(arr[0], arr[i]);
        heapSize--;
        maxHeapify(arr, 0);
    }
}

/**
 * Sorting algorithm which uses max-heap data structure.
 * First builds the array as a heap and then takes the largest element
 * from the root of the heap and places into a sorted_array starting from the end.
 * It repeats these steps until the heap is empty.
 * 
 * @param arr the array to be sorted
*/

void heapSortModified(vector<int>& arr) {
    buildMaxHeap(arr);
    for(int i = arr.size() - 1; i >= 1; i--){
        swap(arr[0], arr[i]);
        heapSize--;
        newApproach(arr, 0);
    }
}

void printArr(vector<int>& arr) {
    int length = arr.size();
    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << endl;
}