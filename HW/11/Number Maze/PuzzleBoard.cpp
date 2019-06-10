/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #11
    @file PuzzleBoard.cpp
    @author Taiyr Begeyev
    @version 1.0 10/05/19
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
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#include "PuzzleBoard.h"
using namespace std;

int PuzzleBoard::getNode(int x, int y) {
    return boardSize * x + y;
}

bool PuzzleBoard::outOfGrid(int x, int y) {
    return x < 0 || y < 0 || x >= boardSize || y >= boardSize;
}

/* 
    @brief constructor should create the graph (as you defined
    it in subpoint (a) with the values from fields. If fields
    is null, then initialize the fields of the board with random
    values between 1 and boardSize-1. 
*/

PuzzleBoard::PuzzleBoard(int boardSize, int** fields) {
    if (fields == nullptr) {
        // randomly generate grid if none is provided
        srand(time(NULL));
        // dynamically allocate memory
        fields = new int*[boardSize];
        if (fields == nullptr) {
            cerr << "Error allocating memory" << endl;
            exit(1);
        }
        for (int i = 0; i < boardSize; i++) {
            fields[i] = new int[boardSize];
        }

        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                fields[i][j] = rand() % boardSize + 1;
            }
        }
    }

    this->boardSize = boardSize;
    nodes = boardSize * boardSize;
    // allocate memory for edges
    edges.resize(nodes, set<int>());

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            int currentNode = getNode(i, j);
            int nextNode;
            if (!outOfGrid(i + fields[i][j], j)) {
                nextNode = getNode(i + fields[i][j], j);
                edges[currentNode].insert(nextNode);
            }
            if (!outOfGrid(i - fields[i][j], j)) {
                nextNode = getNode(i - fields[i][j], j);
                edges[currentNode].insert(nextNode);
            }
            if (!outOfGrid(i, fields[i][j] + j)) {
                nextNode = getNode(i, fields[i][j] + j);
                edges[currentNode].insert(nextNode);
            }
            if (!outOfGrid(i, j - fields[i][j])) {
                nextNode = getNode(i, j - fields[i][j]);
                edges[currentNode].insert(nextNode);
            }
        }
    }

    this->fields.resize(boardSize, vector<int>(boardSize));
    for(int i = 0; i < boardSize; i++){
        for(int j = 0; j < boardSize; j++){
            this->fields[i][j] = fields[i][j];
        }
    }
    // Set initial position to (0, 0) (top left corner)
    currentX = 0;
    currentY = 0;
}

/* 
    @brief makes the move (if valid), direction is 0 for up, 1 for right,
    2 for down, 3 for left. Returns true if the move was valid, 
    false otherwise. 
*/
bool PuzzleBoard::makeMove(int direction) {
    int newX, newY, current, next;
    set<int>::iterator it;
    switch (direction) {
        case 0:
            newX = currentX - fields[currentX][currentY];
            newY = currentY;
            if (outOfGrid(newX, newY)) {
                return false;
            }
            current = getNode(currentX, currentY);
            next = getNode(newX, newY);
            it = edges[current].find(next);
            if (it == edges[current].end()) {
                return false;
            }
            currentX = newX;
            currentY = newY;
            break;
        case 1:
            newX = currentX;
            newY = currentY + fields[currentX][currentY];
            if(outOfGrid(newX, newY)) {
                return false;
            }
            current = getNode(currentX, currentY);
            next = getNode(newX, newY);
            it = edges[current].find(next);
            if(it == edges[current].end()) {
                return false;
            }
            currentX = newX;
            currentY = newY;
            break; 
        case 2:
            newX = currentX + fields[currentX][currentY];
            newY = currentY;
            if (outOfGrid(newX, newY)) {
                return false;
            }
            current = getNode(currentX, currentY);
            next = getNode(newX, newY);
            it = edges[current].find(next);
            if (it == edges[current].end()) {
                return false;
            }
            currentX = newX;
            currentY = newY;
            break;
        case 3:
            newX = currentX;
            newY = currentY - fields[currentX][currentY];
            if (outOfGrid(newX, newY)) {
                return false;
            }
            current = getNode(currentX, currentY);
            next = getNode(newX, newY);
            it = edges[current].find(next);
            if (it == edges[current].end()) {
                return false;
            }
            currentX = newX;
            currentY = newY;
            break;
    }
    return true;
}

/* 
    @brief Returns false if game is not over yet, true if puzzle was solved 
*/
bool PuzzleBoard::getResult() {
    return currentX == boardSize - 1 && currentY == boardSize - 1;
}

/*
    @brief oveloaded operator to print the grid
*/

ostream &operator<<(std::ostream &out, PuzzleBoard const &grid) {
    for(int i = 0; i < grid.boardSize; i++) {
        for(int j = 0; j < grid.boardSize; j++) {
            out << grid.fields[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

/* @brief returns the minimum number of moves needed to solve the puzzle, 
    and -1 if it is not solvable. 
*/
int PuzzleBoard::solve() {
}