/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #7
    @file Stack.cpp
    @author Taiyr Begeyev
    @version 1.0 04/04/19
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
#include <cstdlib>
#include "Stack.h"
#include <stdio.h> 
#include <stdlib.h> 
using namespace std;

template <class T>
Stack<T>::Stack() {
    top = nullptr;
    size = -1;
    current_size = 0;
}

template <class T>
Stack<T>::Stack(int newSize) {
    top = nullptr;
    size = newSize;
    current_size = 0;
}

// methods
template <class T>
void Stack<T>::push(T x) {
    // base case
    if (current_size >= size && size != -1) {
        cerr << "Stack Overflow" << endl;
    }
    else {
        // create a New Node
        StackNode *newNode = new StackNode;
        //newNode = (StackNode*) malloc(sizeof(StackNode));
        newNode->data = x;
        newNode->next = nullptr;

        // connect to the top
        newNode->next = top;
        // new top
        top = newNode;

        // increase the size of Stack
        current_size++;
        cout << "Pushing " << x << " to the Stack" << endl;
    }
}

template <class T>
T Stack<T>::pop() {
    // base case
    if (current_size <= 0) {
        cerr << "Stack Underflow" << endl;
    }
    else {
        T popped = top->data;
        struct StackNode *temp;
        temp = top->next;
        delete top;
        top = temp; 
        return popped;
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    if (top == nullptr)
        return true;
    else 
        return false;
}

template <class T>
void Stack<T>::print() {
    cout << "Printing numbers:" << endl;
    struct StackNode *cursor;
    for (cursor = top; cursor != NULL; cursor = cursor->next) {
        cout << cursor->data << " ";
    }
    cout << endl;
}


// Instantiate the class with needed types
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<bool>;
template class Stack<char>;
template class Stack<std::string>;