/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #6
    @file CountingSort.cpp
    @author Taiyr Begeyev
    @version 1.0 25/03/19
*/

/*
__________           .__                   
\__    ___/ _____    |__|  ___.__. _______ 
  |    |    \__  \   |  | <   |  | \_  __ \
  |    |     / __ \_ |  |  \___  |  |  | \/
  |____|    (____  / |__|  / ____|  |__|   
                \/        \/              
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void CountingSort(int*, int);
void printArr(int*, int);

int main() {
    int sequence [] = {9, 1, 6, 7, 6, 2, 1};
    CountingSort(sequence, 7);
    printArr(sequence, 7);
    return 0;
}

/**
 * @brief Counting Sort Algorithm Implementation
 * 
 * Algorithm assumes that each of the input elements
 * is an integer in the range 0 to k, for some k. It
 * determines the number of elements less than x, for 
 * each input element x. It uses the information to place
 * element x directly into its position in the output array
 * 
 * @param A - array to be sorted
 * @param n - number of elements in the array
*/

void CountingSort(int *A, int n) {
    // create Auxiliary Array 
    int max = *max_element(A, A + n);
    int min = *min_element(A, A + n);
    int range = max - min + 1;
    int *C = new int[range];
    // create the resultant array
    int *B = new int[n];

    // initialize the array with zeros
    for (int i = 0; i < range; i++) {
        C[i] = 0;
    }
    // iterate through array, calculate and the number
    // of occurences of A[i] to C[A[i]]
    for (int i = 0; i < n; i++) {
        C[A[i] - min]++;
    }

    // determine for each i = 0 .. k how many input elements
    // are less than or equal to i
    for (int i = 1; i < range; i++) {
        C[i] += C[i - 1];
    }

    // place each element from C into its correct sorted position
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i] - min] - 1] = A[i];
        C[A[i] - min]--;
    }
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
    
    // deallocate
    delete [] B;
    delete [] C;
}

/**
 * @brief print the passed Array
 * @param array - to be printed
 * @param n - number of elements
*/

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}