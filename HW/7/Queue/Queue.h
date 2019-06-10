/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #7
    @file Queue.h
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
#ifndef _QUEUE_H
#define _QUEUE_H

template <class T>
class Stack {
    private: 
        template <class U>
        friend class Queue;
        // linked list
        struct StackNode {
            T data;
            struct StackNode *next;
        };
        StackNode *top; // top of Stack
        int size; // -1 if not set, value otherwise
        int current_size; //unused if size = -1
    public:
        // constructors
        Stack();
        Stack(int);
        // methods
        void push(T);
        T pop();
        bool isEmpty();
        void print();
};

template <class U>
class Queue {
    private: 
        Stack<U> *myStack1;
        Stack<U> *myStack2;
    public:
        // constructors
        Queue();
        Queue(int);
        // destructors
        ~Queue();
        // methods
        void enqueue(U);
        U dequeue();
        void print();
};

#endif