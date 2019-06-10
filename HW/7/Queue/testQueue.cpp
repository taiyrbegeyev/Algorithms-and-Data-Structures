/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #7
    @file testQueue.cpp
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

int main() {
    Queue<int> myQueue(2);
    myQueue.enqueue(1);
    myQueue.print();
    myQueue.enqueue(2);
    myQueue.print();

    // check for overflow
    myQueue.enqueue(3);

    myQueue.print();
    cout << "Popping " << myQueue.dequeue() << endl;
    myQueue.print();
    cout << "Popping " << myQueue.dequeue() << endl;

    // check for underflow
    myQueue.dequeue();
    
    return 0;
}