/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #8
    @file hashTable.cpp
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

/*
    @brief parametrical constructor
*/

Node::Node(int key, int value) {
    this->key = key;
    this->value = value;
}

/*
    @brief constructor
    by default maxSize is 100
*/

HashTable::HashTable(int maxSize) {
    this->maxSize = maxSize;
    currentSize = 0;

    // allocate memory
    arr = new Node*[maxSize];
    for (int i = 0; i < maxSize; i++) {
        arr[i] = nullptr;
    }
}

/*
    @brief destructor
*/
HashTable::~HashTable() {
    for (int i = 0; i < maxSize; i++) {
        delete arr[i];
    }
    delete[] arr;
}

/*
    @brief Hash Function
*/

int HashTable::hashCode(int key) {
    return key % maxSize;
}

/*
    @brief Insert element at a key
*/

void HashTable::insertCode(int key, int value) {
    int hashValue = (hashCode(key)) % maxSize;
    int init = -1;

    int i = 1;
    while (hashValue != init && arr[hashValue]!= nullptr && arr[hashValue]->key != key)
    {
        if (init == -1) {
            init = hashValue;
        }
        hashValue = (hashCode(key) + i) % maxSize;
        i++;
    }

    if (arr[hashValue] == nullptr)
    {
        arr[hashValue] = new Node(key, value);
        currentSize++;
    }
}

/*
    @brief Search for an element with the given key
    @return the position of the element we are looking for
*/
int HashTable::get(int key) {
    for (int i = 0; i < maxSize; i++) {
        int hashValue = (hashCode(key) + i) % maxSize;
        if (arr[hashValue] == nullptr) {
            return -1;
        }
        else if (arr[hashValue]->key == key) {
            return hashValue;
        }
    }
    return -1;
}   

/*
    @brief check whether the HashTable is empty
*/

bool HashTable::isEmpty() {
    return currentSize == 0;
}