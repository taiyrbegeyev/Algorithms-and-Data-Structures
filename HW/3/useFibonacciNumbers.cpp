/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #3
    @file useFibonacciNumbers.cpp
    @author Taiyr Begeyev
    @version 1.0 27/02/19
*/

/*
__________          .__                   
\__    ___/ _____    |__|  ___.__. _______ 
  |    |    \__  \   |  | <   |  | \_  __ \
  |    |     / __ \_ |  |  \___  |  |  | \/
  |____|    (____  / |__|  / ____|  |__|   
                \/        \/              
*/

#include "fibonacciNumbers.h"
#include <chrono>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
using namespace std::chrono;

int main() {
    ofstream naiveFile, bottomUpFile, closedFormFile, matrixFile;

    int choice;
    cout << "What function would you like to run" << endl;
    cout << "1. Naive Recursive" << endl;
    cout << "2. Bottom Up Approach" << endl;
    cout << "3. Closed Form" << endl;
    cout << "4. Matrix Represenation" << endl;
    cout << "Enter the corresponding number: ";
    cin >> choice; 

    int n = 0;
    switch(choice) {
        case 1: 
            naiveFile.open("fibonacciNaive.dat", ios::out | ios::trunc);
            /* (1) Naive method*/
            while(true) {
                // if it is more than 45, it takes bunch of damn time
                if (n > 45) {
                    naiveFile.close();
                    break;
                }

                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                fibonacciNaive(n);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();

                double duration = duration_cast<nanoseconds>(t2 - t1).count();

                naiveFile << n << " " << setprecision(15) << duration << endl;
                n++;
            }
            
            break;
        case 2: 
            bottomUpFile.open("fibonacciBottomUp.dat", ios::out | ios::trunc);
            /* (2) Bottom Up Approach */
            n = 0;
            while(true) {
                if (n > 100) {
                    bottomUpFile.close();
                    break;
                }

                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                fibonacciBottomUp(n);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();

                double duration = duration_cast<nanoseconds>((t2 - t1)).count();

                bottomUpFile << n << " " << duration << endl;
                n++;
            }
            break;
        case 3: 
            closedFormFile.open("fibonacciClosedForm.dat", ios::out | ios::trunc);
            /* (3) Closed Form */
            while(true) {
                if (n > 100) {
                    closedFormFile.close();
                    break;
                }

                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                fibonacciClosedForm(n);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();

                double duration = duration_cast<nanoseconds>(t2 - t1).count();

                closedFormFile << n << " " << duration << endl;
                n++;
            }
        case 4: 
            matrixFile.open("fibonacciMatrix.dat", ios::out | ios::trunc);
            /* (4) Matrix represenation */
                while(true) {
                if (n > 100) {
                    matrixFile.close();
                    break;
                }

                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                fibonacciMatrix(n);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();

                double duration = duration_cast<nanoseconds>(t2 - t1).count();

                matrixFile << n << " " << duration << endl;
                n++;
            }        
    }

    return 0;
}


 
 
 