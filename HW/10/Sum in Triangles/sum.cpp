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
#include <algorithm>
using namespace std;

/*
    @brief finds and prints the max sum from top to bottom 
    of the Triangle

    At each level we have to choose whether to pick the number from
    left or right on our path. In order to make the optimal choice, which maximizes
    the sum, we need to know how large the sum is if we go either way. 
    We start from the row before the last row. We use the following formula: a + max(b, c),
    where a is the current element and b and c are "adjacent element" (left and right element
    on the next row). We keep using this formula until we reach the top of the triangle
    (the first row), which will be equal to the max sum
    We dynamically allo
*/

void sumInTriangle(int** arr, int n) {
    // dynamically allocate memory
    int** arr2 = new int*[n];
    for (int i = 0; i < n; i++) {
        arr2[i] = new int[n];
    }
    
    // copy the arr to it
    for(int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            arr2[i][j] = arr[i][j];
        }
    }

    // use the formula
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]); 
        }
    }

    cout << "Sum = " << arr[0][0] << endl;

    // determine the path. That's where our second array comes in handy.
    // Since arr doesn't contain values of the triangle anymore, but rather sums
    int max_pos = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i][max_pos] < arr[i][max_pos + 1]) {
            max_pos++;
        }

        cout << arr2[i][max_pos] << " ";
    }
    cout << endl;

    // deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] arr2[i];
    }
    delete[] arr2;
}

int main() {
    while(true) {
        try {
            int n;
            cout << "Enter the number of lines: ";
            cin >> n;
            if ( (n <= 1) || (n > 100) ) {
                throw "Wrong range of n";
            }

            // dynamically allocate memory
            int **arr = new int*[n];
            for (int i = 0; i < n; i++) {
                arr[i] = new int[n];
            }

            // input
            for(int i = 0; i < n; i++) {
                for (int j = 0; j <= i; j++) {
                    cin >> arr[i][j];
                    if (arr[i][j] < 0 || arr[i][j] > 10000) {
                        throw "Wrong value of the triangle element";
                    }
                }
            }

            sumInTriangle(arr, n);

            // deallocate memory
            for (int i = 0; i < n; i++) {
                delete[] arr[i];
            }
            delete[] arr;
            break;
        }
        catch(const char* msg) {
            cerr << "Exception: " << msg << endl;
        }
    }
    return 0;
}