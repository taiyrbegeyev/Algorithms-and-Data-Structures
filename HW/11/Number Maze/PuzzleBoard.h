/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #11
    @file PuzzleBoard.h
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

#ifndef _PUZZLE_BOARD_H
#define _PUZZLE_BOARD_H
#include <iostream>
#include <vector>
#include <set>

class PuzzleBoard {
private:
    int boardSize;
    int nodes;
    int currentX;
    int currentY;
    std::vector<std::set<int>> edges;
    std::vector<std::vector<int>> fields;
    // methods
    int getNode(int, int);
    bool outOfGrid(int, int);
public:
    // Subpoint (b)
    PuzzleBoard(int boardSize, int** fields = nullptr);
    bool makeMove(int direction);
    bool getResult();
    friend std::ostream &operator<<(std::ostream &os, PuzzleBoard const &m);
    // Subpoint (c)
    int solve();
};

#endif