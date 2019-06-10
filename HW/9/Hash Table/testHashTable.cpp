/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #8
    @file testHashTable.cpp
    @author Taiyr Begeyev
    @version 1.0 22/04/19
*/

/*
__________           .__                   
\__    ___/ _____    |__|  ___.__. _______ 
  |    |    \__  \   |  | <   |  | \_  __ \
  |    |     / __ \_ |  |  \___  |  |  | \/
  |____|    (____  / |__|  / ____|  |__|   
                \/        \/              
*/
#include "hashTable.h"
#include <iostream>
using namespace std;

int main() {
    HashTable hash(100);

    cout << "Is empty: " << hash.isEmpty() << endl;

    hash.insertCode(1001, 10);
    hash.insertCode(2222, 37);
    hash.insertCode(3333, 16);
    hash.insertCode(46667, 67);
    hash.insertCode(5776, 12);
    hash.insertCode(107676, 8);
    hash.insertCode(107677, 8);

    cout << hash.get(1001) << endl;
    cout << hash.get(2222) << endl;
    cout << hash.get(3333) << endl;
    cout << hash.get(46667) << endl;
    cout << hash.get(5776) << endl;
    cout << hash.get(6) << endl;
    cout << hash.get(107676) << endl;
    cout << hash.get(107677) << endl;

    cout << "Is empty: " << hash.isEmpty() << endl;

    return 0;
}