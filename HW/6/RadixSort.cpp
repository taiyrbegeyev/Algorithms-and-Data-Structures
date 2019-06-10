/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #6
    @file RadixSort.cpp
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

void BucketSort(vector<int>&, int);
void RadixSort(vector<int>&);
void print(vector<int>&);

int main() {
    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    RadixSort(arr);
    print(arr);

    return 0;
}

/**
 * @brief Bucket Sort implementation algorithm
 * 
 * Divides the interval into n equal-sized buckets
 * and then distributes the n input numbers into the buckets
 * 
 * @param arr - array to be sorted
 * @param n - number of elements in the array
*/

void BucketSort(vector<int>& arr, int exp) {
    // to make sure that we don't divide by 0
    if (exp == 0) {
        return;
    }
    
    // set up an array of initially empty "buckets"
    vector<int> b[10];

    // go over the original array, putting each object
    // in its bucket
    for(int i = 0; i < arr.size(); i++){
        int bi = (arr[i] / exp) % 10;
        b[bi].push_back(arr[i]);
    }

    // sort each non-empty bucket
    for(int i = 0; i < 10; i++){
        if(b[i].size() > 1){
            BucketSort(b[i], exp / 10);
        }
    }
    arr.clear();
    // gather all buckets
    int idx = 0;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < b[i].size(); j++)
            arr.push_back(b[i][j]);
}

void RadixSort(vector<int>& arr) {
    int maxEl = 0;
    // find the largest number (number with most digits)
    for(int i = 0; i < arr.size(); i++){
        maxEl = max(maxEl, arr[i]);
    }

    // find exponent
    int exp = 1;
    while(maxEl /exp > 0) 
        exp *= 10;

    exp /= 10;
    BucketSort(arr, exp);
}

/**
 * @brief print the passed vector container
 * @param arr - to be printed
 * @param n - number of elements
*/

void print(vector<int>& arr) {
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}