 /*
    Algorithms and Data Structures
    Spring 2019
    Assignment #3
    @file fibonacciNumbers.cpp
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
#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>
using namespace std::chrono;

/* 
    (1) Naive Recursion 
*/
unsigned long long fibonacciNaive(int n) {
    if(n < 2)
        return n;
    else 
        return fibonacciNaive(n - 2) + fibonacciNaive(n - 1);
}

/*
    (2) Bottom Up Approach
*/
unsigned long long fibonacciBottomUp(int n) {
    unsigned long long arr[n + 1];
    if (n < 2) 
        return n;
    else {
        arr[0] = 0;
        arr[1] = 1;

        for (int i = 2; i <= n; i++)
            arr[i] = arr[i - 2] + arr[i - 1];
    }
    return arr[n];
}

/*
    (3) Closed form method
*/
unsigned long long fibonacciClosedForm(int n) {
    unsigned long long result = (1 / sqrt(5)) * ceil(pow(((1 + sqrt(5)) / 2), n));
    return result;
}

unsigned long long power(int base, int exp) {
    if(exp == 0)
        return 1;
    else 
        return base * power(base, exp - 1);
}

/*
    (4) Matrix Representation
*/
unsigned long long matrixToThePow(unsigned long long arr[2][2], int exp) {
    unsigned long long dummy[2][2];
    unsigned long long basic[2][2] = {{1, 1}, {1, 0}};

    if (exp == 0) {
        return arr[0][1];
    }
    else {
        for (int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                dummy[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    dummy[i][j] = dummy[i][j] + arr[i][k] * basic[k][j];
            }
        }
        return matrixToThePow(dummy, exp - 1); 
    }
}

unsigned long long fibonacciMatrix(int n) {
    if(n == 0)
        return 0;
    unsigned long long arr[2][2] = {{1, 1}, {1, 0}};
    return matrixToThePow(arr, n - 1);
}

/**
 * (b)
 * */
