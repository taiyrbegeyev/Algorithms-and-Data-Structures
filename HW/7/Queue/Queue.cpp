/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #7
    @file Queue.cpp
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
#include "Queue.h"
#include <iostream>
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
}

template <class T>
T Stack<T>::pop() {
    T popped = top->data;
    struct StackNode *temp;
    temp = top->next;
    delete top;
    top = temp; 
    return popped;
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

// empty constructor
template <class U>
Queue<U>::Queue() {
    myStack1 = new Stack<U>();
    myStack2 = new Stack<U>();
}

// parametrical constructor
template <class U>
Queue<U>::Queue(int newSize) {
    myStack1 = new Stack<U>(newSize);
    myStack2 = new Stack<U>(newSize);
}

// methods
template <class U>
void Queue<U>::enqueue(U x) {
    if (myStack1->current_size >= myStack1->size && myStack1->size != -1) {
        cerr << "Queue Overflow" << endl;
    }
    else {
        // move all elements from Stack 1 to Stack 2 and empty it
        while(!(myStack1->isEmpty())) {
            myStack2->push(myStack1->top->data);
            myStack1->pop();
        }

        // push new element to Stack 1
        myStack1->push(x);

        // push everything back to Stack 1
        while(!(myStack2->isEmpty())) {
            myStack1->push(myStack2->top->data);
            myStack2->pop();
        }
    }
}

template <class U>
U Queue<U>::dequeue() {
    // base case
    if (myStack1->isEmpty()) {
        cerr << "Queue Underflow" << endl;
    }
    else {
        return myStack1->pop();
    }
}

template <class U>
void Queue<U>::print() {
    myStack1->print();
}

// desctructor
template <class U>
Queue<U>::~Queue() {
    delete myStack1;
    delete myStack2;
}

// Instantiate the class with needed types
template class Stack<int>;
template class Stack<float>;
template class Stack<double>;
template class Stack<bool>;
template class Stack<char>;
template class Stack<std::string>;

template class Queue<int>;
template class Queue<float>;
template class Queue<double>;
template class Queue<bool>;
template class Queue<char>;
template class Queue<std::string>;