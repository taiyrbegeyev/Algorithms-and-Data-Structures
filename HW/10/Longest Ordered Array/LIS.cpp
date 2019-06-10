/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #10
    @file LIS.cpp
    @author Taiyr Begeyev
    @version 1.0 29/04/19
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
#include <vector>
using namespace std;

void print(vector<int> arr) {
    for (int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}

/*
    @brief Find and print Longest Ordered Array

    Create a vector container, which consists of vector containers. 
    arr[i] is a vector itself that stores some subsequence for each 
    element of the array a. Subsequence of each element is composed of
    Longest Ordered Array of this specific element. That's where Dynamic
    Programming Concept comes in handy. Go from left to right towards the
    current element and try to find LIS based on previous elements' LIS  
*/

void findLIS(vector<int> a) {
    int n = a.size();
    // create 2d array
    vector<vector<int>> arr(n);

    // first element of the array a is already LIS of itself
    arr[0].push_back(a[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if ( (a[i] > a[j]) && (arr[j].size() + 1 > arr[i].size()) ) {
                // find the max(arr[j])
                arr[i] = arr[j];
            }
            // push the current element
        }
        arr[i].push_back(a[i]);
    }

    // find the vector container with the longest length
    vector<int> max = arr[0];
    for (vector<int> i: arr) {
        if (i.size() > max.size()) {
            max = i;
        }
    }
    print(max);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findLIS(arr);

    return 0;
}