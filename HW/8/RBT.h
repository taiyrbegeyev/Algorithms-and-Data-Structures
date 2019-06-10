/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #8
    @file RBT.h
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

#ifndef _RBT_H
#define _RBT_H

enum Color {
    RED, BLACK
};

struct Node {
    int data;
    Color color;
    Node *left;
    Node *right;
    Node *parent;
};

class RedBlackTree {
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
    public:
        // constructor
        RedBlackTree();

        // methods
        void insert(int);
        void RBTfixup(Node *&);

        void transplant(Node *&, Node *&);
        void deleteNode(Node *&);
        void deleteNodeFixup(Node *&);
        void deleteByVal(int);

        Node *predessor(const Node *&);
        Node *successor(Node *&);
        Node *getMinimum();
        Node *getMaximum();
        Node *search(int);

        void inOrder(Node *&);
        void print();
};

#endif