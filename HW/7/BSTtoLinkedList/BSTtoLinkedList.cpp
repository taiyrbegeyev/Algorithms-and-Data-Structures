/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #7
    @file BSTtoLinkedList.cpp
    @author Taiyr Begeyev
    @version 1.0 05/04/19
*/
#include <iostream>
using namespace std;

// Doubly Linked List
struct DLL {
    int data;
    struct DLL *prev;
    struct DLL *next;
};
//typedef struct DLL DLL;

// DLL methods
void pushFront(DLL** myList, int ch) {
    DLL* el = new DLL;
    el->data = ch;   
    el->prev = NULL;
    el->next = *myList;

    if ((*myList) != NULL) 
        (*myList)->prev = el; 
  
    (*myList) = el;
}

void printDLL(DLL *myList) {
    DLL* cursor;
    for (cursor = myList; cursor; cursor = cursor->next)
        cout << cursor->data << " ";
    cout << endl;
}

// Binatry Search Tree
struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};
//typedef struct BST BST;

// Binary Search Tree methods
BST* insert(BST *myBST, int x) {
    // create a new Node
    BST* temp = new BST;
    temp->data = x;
    temp->left = temp->right = nullptr;
    
    // If the tree is empty, return a new node
    if (myBST == NULL) 
        return temp;
    
    // recur down the tree
    if (x < myBST->data) 
        myBST->left = insert(myBST->left, x);
    else if (x > myBST->data)
        myBST->right = insert(myBST->right, x);

    return myBST;
}

void ConvertNode(BST *Node, BST **lastNode) {
    if (Node == nullptr)
        return;
    
    BST *current = Node;
    if (current->left != nullptr)
        ConvertNode(current->left, lastNode);
    
    current->left = *lastNode;
    if (*lastNode != nullptr)
        (*lastNode)->right = current;
    
    *lastNode = current;
    if (current->right != nullptr) 
        ConvertNode(current->right, lastNode);
}

BST* Convert(BST *root) {
    BST *lastNode = nullptr;
    ConvertNode(root, &lastNode);
    BST *head = lastNode;
    while(head != nullptr && head->left != nullptr) {
        head = head->left;
    }
    return head;
} 

int main() {
    BST *myBST = nullptr;
    int n;
    cout << "How many elements to insert: ";
    cin >> n;

    int dummy;
    for (int i = 0; i < n; i++) {
        cin >> dummy;
        myBST = insert(myBST, dummy); 
    }
    BST *head = Convert(myBST);
    DLL *myDLL = nullptr;

    // ....

    return 0;
}