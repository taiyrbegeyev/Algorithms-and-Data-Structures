/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #7
    @file testLinkedListtoBST.cpp
    @author Taiyr Begeyev
    @version 1.0 05/04/19
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
#include <string> 
#include <queue> 
using namespace std; 

struct ListNode 
{ 
    int data; 
    ListNode* next; 
}; 

struct BinaryTreeNode 
{ 
    int data; 
    BinaryTreeNode *left, *right; 
}; 
  
void push(struct ListNode** head_ref, int new_data) 
{ 
    // allocate node and assign data 
    struct ListNode* new_node = new ListNode; 
    new_node->data = new_data; 
  
    // link the old list off the new node 
    new_node->next = (*head_ref); 
  
    // move the head to point to the new node 
    (*head_ref)    = new_node; 
} 
  
// method to create a new binary tree node from the given data 
BinaryTreeNode* newBinaryTreeNode(int data) 
{ 
    BinaryTreeNode *temp = new BinaryTreeNode; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// converts a given linked list representing a complete binary tree into the 
// linked representation of binary tree. 
void convertList2Binary(ListNode *head, BinaryTreeNode* &root) 
{ 
    // queue to store the parent nodes 
    queue<BinaryTreeNode *> q; 
  
    // Base Case 
    if (head == NULL) 
    { 
        root = NULL; // Note that root is passed by reference 
        return; 
    } 
  
    root = newBinaryTreeNode(head->data); 
    q.push(root); 
  
    // advance the pointer to the next node 
    head = head->next; 
  
    // until the end of linked list is reached, do the following steps 
    while (head) 
    { 
        BinaryTreeNode* parent = q.front(); 
        q.pop(); 
  
        BinaryTreeNode *leftChild = NULL, *rightChild = NULL; 
        leftChild = newBinaryTreeNode(head->data); 
        q.push(leftChild); 
        head = head->next; 
        if (head) 
        { 
            rightChild = newBinaryTreeNode(head->data); 
            q.push(rightChild); 
            head = head->next; 
        } 
  
        parent->left = leftChild; 
        parent->right = rightChild; 
    } 
} 
  
void inorderTraversal(BinaryTreeNode* root) 
{ 
    if (root) 
    { 
        inorderTraversal( root->left ); 
        cout << root->data << " "; 
        inorderTraversal( root->right ); 
    } 
} 
  
int main() 
{ 
    struct ListNode* head = NULL; 
    push(&head, 36);  
    push(&head, 30); 
    push(&head, 25); 
    push(&head, 15); 
    push(&head, 12); 
    push(&head, 10); 
  
    BinaryTreeNode *root; 
    convertList2Binary(head, root); 
  
    cout << "BST is " << endl; 
    inorderTraversal(root); 
    return 0; 
} 
