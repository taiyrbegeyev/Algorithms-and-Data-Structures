/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #7
    @file Stack.h
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
#ifndef _STACK_H
#define _STACK_H

template <class T>
class Stack {
    private: 
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
#endif
