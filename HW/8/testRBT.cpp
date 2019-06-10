/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #8
    @file testRBT.cpp
    @author Taiyr Begeyev
    @version 1.0 12/04/19
*/

/*
__________           .__                   
\__    ___/ _____    |__|  ___.__. _______ 
  |    |    \__  \   |  | <   |  | \_  __ \
  |    |     / __ \_ |  |  \___  |  |  | \/
  |____|    (____  / |__|  / ____|  |__|   
                \/        \/              
*/
#include "RBT.h"
#include <iostream>
using namespace std;

int main() {
    RedBlackTree myRBT;
    myRBT.insert(13);
    myRBT.insert(44);
    myRBT.insert(37);
    myRBT.insert(7);
    myRBT.insert(22);
    myRBT.insert(16);
    myRBT.print();

    return 0;
}