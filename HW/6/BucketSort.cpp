/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #6
    @file BucketSort.cpp
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

void BucketSort(vector<float>&);
void printArr(vector<float>&);

int main() {
    vector<float> sequence = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
    BucketSort(sequence);
    printArr(sequence);
    return 0;
}

/**
 * @brief Bucket Sort implementation algorithm
 * 
 * Divides the interval into n equal-sized buckets
 * and then distributes the n input numbers into the buckets
 * 
 * @param A - array to be sorted
 * @param n - number of elements in the array
*/

void BucketSort(vector<float> &arr) {
    int n = arr.size();
    // set up an array of initially empty "buckets"
    vector<float> bucket[n];  

    // go over the original array, putting each object
    // in its bucket
    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        bucket[bi].push_back(arr[i]);
    }

    // sort each non-empty bucket
    for (int i = 0; i < n; i++) {
        sort(bucket[i].begin(), bucket[i].end());
    }
    arr.clear();
    // gather all buckets
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucket[i].size(); j++)
            arr.push_back(bucket[i][j]);
    }
}

/**
 * @brief print the passed Array
 * @param array - to be printed
 * @param n - number of elements
*/

void printArr(vector<float>& arr) {
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    cout << endl;
}