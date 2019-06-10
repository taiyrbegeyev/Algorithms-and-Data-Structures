/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #8
    @file RBT.cpp
    @author Taiyr Begeyev
    @version 1.0 12/04/19
*/

/*
__________           .__                   
\__    ___/ _____    |__|  ___.__. _______ 
  |    |    \__  \   |  | <   |  | \_  __ \
  |    |     / __ \_ |  |  \___  |  |  | \/
  |____|    (____  / |__|  / ____|  |__|   
                \/        \/              
*/
#include "RBT.h"
#include <iostream>
#include <queue>
using namespace std;

// constructor
RedBlackTree::RedBlackTree() {
    root = nullptr;
}

// methods
void RedBlackTree::rotateLeft(Node* &myNode) {
    struct Node *y = myNode->right;
    myNode->right = y->left;

    if (y->right != nullptr) {
        y->right->parent = myNode;
    }
    
    y->parent = myNode->parent;
    if (myNode->parent == nullptr) {
        root = y;
    }
    else if (myNode == myNode->parent->left) {
        myNode->parent->left = y;
    }
    else {
        myNode->parent->right = y;
    }
    y->left = myNode;
    myNode->parent = y;
}

void RedBlackTree::rotateRight(Node* &myNode) {
    struct Node *y = myNode->left;
    myNode->left = y->right;

    if (y->left != nullptr) {
        y->left->parent = myNode;
    }

    y->parent = myNode->parent;
    if (myNode->parent == nullptr) {
        root = y;
    }
    else if (myNode == myNode->parent->left) {
        myNode->parent->left = y;
    }
    else {
        myNode->parent->right = y;
    }
    y->right = myNode;
    myNode->parent = y;
}

void RedBlackTree::RBTfixup(Node* &myNode) {
    Node *parent = NULL; 
    Node *grandParent = NULL; 
  
    while ((myNode != root) && (myNode->color != BLACK) && (myNode->parent->color == RED)) { 
        parent = myNode->parent; 
        grandParent = myNode->parent->parent; 
  
        if (parent == grandParent->left) { 
            struct Node *uncle = grandParent->right; 
            if (uncle != NULL && uncle->color == RED) { 
                grandParent->color = RED; 
                parent->color = BLACK; 
                uncle->color = BLACK; 
                myNode = grandParent; 
            } 
            else { 
                if (myNode == parent->right) { 
                    rotateLeft(parent); 
                    myNode = parent; 
                    parent = myNode->parent; 
                } 
                rotateRight(grandParent); 
                swap(parent->color, grandParent->color); 
                myNode = parent; 
            } 
        } 
        else { 
            Node *uncle = grandParent->left; 
            if ((uncle != NULL) && (uncle->color == RED)) { 
                grandParent->color = RED; 
                parent->color = BLACK; 
                uncle->color = BLACK; 
                myNode = grandParent; 
            } 
            else { 
                if (myNode == parent->left) { 
                    rotateRight(parent); 
                    myNode = parent; 
                    parent = myNode->parent; 
                } 
                rotateLeft(grandParent); 
                swap(parent->color, grandParent->color); 
                myNode = parent; 
            } 
        } 
    } 
    root->color = BLACK; 
}

void RedBlackTree::insert(int info) {
    // create a New Node
    struct Node *newNode = new struct Node;
    newNode->data = info;
    newNode->color = RED;   //color it red
    newNode->parent = newNode->left = newNode->right = nullptr;

    struct Node *y = nullptr;
    struct Node *x = root;

    while (x != nullptr) {
        y = x;
        if (newNode->data < x->data) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    newNode->parent = y; 
    if (y == nullptr) {
        root = newNode;
    }
    else if (newNode->data < y->data) {
        y->left = newNode;
    }
    else {
        y->right = newNode;
    }
    // if RBT properties are violated, fix them
    RBTfixup(newNode);
}

Node* RedBlackTree::getMinimum() {
    struct Node* current = root;
    while(current->left != nullptr) {
        current = current->left;
    }
    return current;
}

Node* RedBlackTree::getMaximum() {
    struct Node* current = root;
    while(current->right != nullptr) {
        current = current->right;
    }
    return current;
}

Node* RedBlackTree::predessor(const Node* &myNode) {
    if (myNode->left != nullptr) {
        return getMaximum();
    }

    struct Node *y = myNode->parent;
    while(y != nullptr && myNode == y->left) {
        myNode = y;
        y = y->parent;
    }
}

Node* RedBlackTree::successor(Node* &myNode) {
    if (myNode->right != nullptr) {
        return getMinimum();
    }

    struct Node *y = myNode->parent;
    while(y != nullptr && myNode == y->right) {
        myNode = y;
        y = y->parent;
    }
    return y;
}

// replaces a subtree rooted at node u with a subtree rooted at node v
void RedBlackTree::transplant(Node* &u, Node* &v) {
    if (u->parent == nullptr) {
        root = v;
    }
    else if (u == u->parent->left) {
        u->parent->left = v;
    }
    else {
        u->parent->right = v;
    }
    v->parent = u->parent;
}

void RedBlackTree::deleteNodeFixup(Node* &x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            struct Node* w = x->parent->right;
            if (w->color == RED) {//Case1
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft(x->parent);
                w = x->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } 
            else if (w->right->color == BLACK) {
                w->left->color = BLACK;
                w->color = RED;
                rotateRight(w);
                w = x->parent->right;
            } 
            else {
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft(x->parent);
                x = root;
            }
        } 
        else {
            struct Node* w = x->parent->left;
            if (w->color == RED) {//Case1
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight(x->parent);
                w = x->parent->left;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } 
            else if (w->left->color == BLACK) {
                w->left->color = BLACK;
                w->color = RED;
                rotateLeft(w);
                w = x->parent->left;
            } 
            else {
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RedBlackTree::deleteNode(Node* &z) {
     struct Node * x, * y;  
 
    if (z->left == nullptr || z->right == nullptr) {
        y = z;
    } else {
        y = successor(z);
    }  
 
    if (y->left != nullptr) {
        x = y->left;
    } else {
        x = y->right;
    }  
 
    x->parent = y->parent;  
 
    if (y->parent == nullptr) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }  
 
    if (y != z) {
        z->data = y->data;
    }  
 
    if (y->color == BLACK) {
        deleteNodeFixup(x);
    }
}

void RedBlackTree::deleteByVal(int n) { 
    if (root == NULL) 
      // Tree is empty 
      return; 
  
    Node *v = search(n), *u; 
  
    if (v->data != n) { 
      cout << "No node found to delete with value:" << n << endl; 
      return; 
    } 
  
    deleteNode(v); 
} 

Node* RedBlackTree::search(int info) {
    struct Node* cursor = root;
    while (cursor != nullptr && info != cursor->data) {
        if (info < cursor->data) {
            cursor = cursor->left;
        }
        else {
            cursor = cursor->right;
        }
    }
    return cursor;
}

void RedBlackTree::inOrder(Node* &myNode) {
    if (myNode == NULL) 
        return; 
    inOrder(myNode->left);
     
    cout << myNode->data << " "; 

    inOrder(myNode->right); 
}

void RedBlackTree::print() {
    /*cout << "Inorder: " << endl; 
    if (root == NULL) { 
        cout << "Tree is empty" << endl; 
    }
    else {
        inOrder(root);
    }
    cout << endl; */
    if (root == NULL) 
        return; 
  
    std::queue<Node *> q; 
    q.push(root); 
  
    while (!q.empty()) { 
        Node *temp = q.front(); 
        cout << temp->data << "  "; 
        q.pop(); 
  
        if (temp->left != NULL) 
            q.push(temp->left); 
  
        if (temp->right != NULL) 
            q.push(temp->right); 
    }  
    cout << endl;
}