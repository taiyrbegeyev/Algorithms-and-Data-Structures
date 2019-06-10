/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #6
    @file SortWords.cpp
    @author Taiyr Begeyev
    @version 1.0 25/03/19
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
#include <vector>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;

void SortWords(vector<string>&);
void print(vector<string>&);

int main() {
    vector<string> words = 
        {
            "word", "category", "cat", "new",
            "news", "world", "bear", "at",
            "work", "time"            
        };

    cout << "Initial sequence: " << endl;
    print(words);
    SortWords(words);
    cout << "Sorted sequence: " << endl;
    print(words); 

    return 0;
}

/**
 * @brief Sort words alphabetically
 * 
 * This algorithm doesn't rely on data comparison methods
 * For characters' of each word two operations are performed: 
 * division by a factor to disregard digit following digit i
 * being processed in the current pass and division modulo radix
 * to disregard all digits preceeding i for a total of 2n digits
 * = O(n) operations.
 * 
 * In each pass, all characters are moved to piles (queues) and then
 * back to words for a total of 2n digits = 0(n) moves. The algorithm
 * requires additional space for piles, which is implemented using STL
 * feature: Queue. My implementation uses only for loops with counters;
 * therefore, it requires the same amount of passes for each case: best,
 * average, worst. The body of the while loop is always executed n times
 * to deque all integers from all queues
*/

void SortWords(vector<string>& words) {
    // sequence of n English words
    int n = words.size();
    // we can consider k to behave like
    // a constant in comparison with n
    const int radix = 128; // ASCII table from 0..127 
    const int k = 10; // the maximum number of digits
    // create radix numbers of queues. In other words, create radix
    // numbers of piles. We will use them to put each character in its pile 
    queue <string> characters[radix];

    int i, j, factor;
    // walk through all digits left -> right
    for (i = 0, factor = 1; i < k; factor *= radix, i++) {
        // walk through all words and put a character on a i position
        // into one of the piles (queue)
        for (j = 0; j < n; j++) {
            int dummy = ((int)(words[j][i]) / factor) % radix;
            characters[dummy].push(words[j]);
        }
        for (i = j = 0; i < radix; i++) {
            while(!characters[i].empty()) {
                words[j++] = characters[i].front(); 
                characters[i].pop();
            }
        }
    }
}

/**
 * @brief print the passed Array
 * @param array - to be printed
 * @param n - number of elements
*/

void print(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl;
}