/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #5
    @file ModifiedQuickSortRandomized.cpp
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
using namespace std;

void randomizedPartition(vector<int> &, int, int, int &, int &);
void partition(vector<int> &, int, int, int &, int &);
void ModifiedQuickSort(vector<int>&, int, int);

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    vector <int> arr = {5, 4, 3, 2, 1};
    int length = arr.size();
    ModifiedQuickSort(arr, 0 , 4);

    for (int i = 0; i < length; i++)
        cout << arr[i] <<  " ";
    cout << endl;

    return 0;
}

void ModifiedQuickSort(vector<int>& arr, int start, int end) {
    if(start < end){
        int lp, rp;
        randomizedPartition(arr, start, end, lp, rp);
        ModifiedQuickSort(arr, start, lp - 1);
        ModifiedQuickSort(arr, lp + 1, rp - 1);
        ModifiedQuickSort(arr, rp + 1, end);
    }
}

void partition(vector<int> &arr, int start, int end, int &lp, int &rp) {
    // I swap the second element and the last element. Then I set the left pivot 
    // to be the smaller element and right pivot to be the greater element.
    swap(arr[start + 1], arr[end]);
    if(arr[start] > arr[end]){
        swap(arr[start], arr[end]);
    }   

    // Left index is start + 1 and right index is end - 1 
    int pivot1 = arr[start];
    int pivot2 = arr[end];
    int idx = start + 1;
    int pivot1Index = start + 1;
    int pivot2Index = end - 1;  
    
    while(idx <= pivot2Index) {

    // Put all elements smaller than the left(smaller) pivot to the left 
    if(arr[idx] < pivot1) {
        swap(arr[idx], arr[pivot1Index]);
        pivot1Index++;
    } 
    else if(arr[idx] >= pivot2) { 
        // Put all elements greater than the right(greater) pivot to the right
        while(arr[pivot2Index] > pivot2 && idx < pivot2Index) pivot2Index--;
        
        swap(arr[idx], arr[pivot2Index]);
        pivot2Index--;  
        // Check if the new swapped element is less than the left pivot. If so, take it to the left side 
        if(arr[idx] < pivot1){
            swap(arr[idx], arr[pivot1Index]);
            pivot1Index++;
        }
    }
    // All the elements between the left and right pivot go in the middle section 
        idx++;
    }

    pivot1Index--;
    pivot2Index++;

    // swap pivots with their cursors(pivot1Index and pivot2Index)
    swap(arr[start], arr[pivot1Index]);
    swap(arr[end], arr[pivot2Index]);   
    lp = pivot1Index;
    rp = pivot2Index;
}

void randomizedPartition(vector<int> & arr, int start, int end, int &lp, int &rp) {
    int p1 = rand() % (end - start + 1) + start;
    int p2 = rand() % (end - start + 1) + start;
    while(p1 == p2){
        p1 = rand() % (end - start + 1) + start;
        p2 = rand() % (end - start +1 ) + start;
    }
    swap(arr[p1], arr[start]);
    swap(arr[p2], arr[start+1]);
    partition(arr, start, end, lp, rp);
}