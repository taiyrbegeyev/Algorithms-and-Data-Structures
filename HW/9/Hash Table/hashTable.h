/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #8
    @file hashTable.h
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

#ifndef _HASHTABLE_H
#define _HASHTABLE_H

class Node  {
    public:
        int key;
        int value;
        Node(int, int);
};

class HashTable {
    private:
        Node **arr;
        int maxSize;
        int currentSize;
    public:
        HashTable(int);
        ~HashTable();
        int hashCode(int);
        void insertCode(int, int);
        int get(int);
        bool isEmpty();
};

#endif