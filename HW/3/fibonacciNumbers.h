 /*
    Algorithms and Data Structures
    Spring 2019
    Assignment #3
    @file fibonacciNumbers.h
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

/**
 * @brief (1) naive recursive method
 *        (2) bottom up method
 *        (3) closed form method
 *        (4) matrix representation
*/
unsigned long long fibonacciNaive(int n); //(1)
unsigned long long fibonacciBottomUp(int n); //(2)
unsigned long long fibonacciClosedForm(int n); //(3)
unsigned long long fibonacciMatrix(int n); //(4)

/**
 * @brief helper functions
*/
unsigned long long  power(int base, int exp);  //for(3)
unsigned long long matrixToThePow(int** arr, int exp); //for (4)
