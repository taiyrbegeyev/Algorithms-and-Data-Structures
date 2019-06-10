/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #7
    @file testStack.cpp
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
#include "Stack.h"
using namespace std;


int main() {
    cout << "Problem 7.1 (a)" << endl;
    Stack<int> myStack(5);
    (myStack.isEmpty()) ? (cout << "Empty" << endl) : (cout << "Not Empty" << endl);

    // check underflow
    myStack.pop();

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    // check overflow
    myStack.push(6);

    myStack.print();
    cout << "Popping " << myStack.pop() << " from the Stack" << endl;
    myStack.print();

    (myStack.isEmpty()) ? (cout << "Empty" << endl) : (cout << "Not Empty" << endl);

    return 0;
}