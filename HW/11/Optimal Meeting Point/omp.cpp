/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #11
    @file omp.cpp
    @author Taiyr Begeyev
    @version 1.0 09/05/19
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
#include <climits>
#include <algorithm>
using namespace std;

// Prototype Declaration
void generalInfo();
int find_meetup_city(int**, int, int, int);

int main() {
    generalInfo();
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    // dynamically allocate 2d array nxn
    int** cities = new int*[n];
    for (int i = 0; i < n; i++) {
        cities[i] = new int[n];
    }

    cout << "Fill out the adjacency matrix " << n << "x" << n << " representing time between cities:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cities[i][j];
            if (cities[i][j] == -1)
                cities[i][j] = INT_MAX;
            if (i == j)
                // distance to itself is obviously zero
                cities[i][j] = 0;
        }
    }

    int p, q;
    cout << "Enter your city: ";
    cin >> p;
    cout << "Enter your friend's city: ";
    cin >> q;
    // call the function to find the optimal meetup point
    cout << "The optimal meetup point: " << find_meetup_city(cities, n, p, q) << endl;

    // deallocate memory
    for (int i = 0; i < n; i++) {
        delete cities[i]; 
    }
    delete[] cities;

    return 0;
}

/*
    @brief finds the target city min which you and your friendshould 
    meet in order to minimize travel time for both of you 
    (you drive towards yourmeeting city simultaneously, so if you travel 
    for x minutes and your friend travels for y minutes, then you will want
    to minimize max(x, y)). The graph is given to youwith an adjacency  matrix, 
    where each entry xij represents the time (in minutes) that it takes to 
    travel from city i to city j
*/

int find_meetup_city(int** cities, int number_of_cities, int your_city, int friend_city) {
    // initialize the solution matrix as the input graph as a first step
    int dist[number_of_cities][number_of_cities];
    for (int i = 0; i < number_of_cities; i++) {
        for (int j = 0; j < number_of_cities; j++) {
            dist[i][j] = cities[i][j];
        }
    }

    // Floyd Warshall Algorithm
    for (int k = 0; k < number_of_cities; k++) {
        for (int i = 0; i < number_of_cities; i++) {
            for (int j = 0; j < number_of_cities; j++) {
                // If vertex k is on the shortest path from 
                // i to j, then update the value of dist[i][j] 
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            }
        }
    }

    /* Finding the optimal meeting city */
    int res = INT_MAX;
    int city;
    for(int i = 0; i < number_of_cities; i++) {
        if (res > max(dist[your_city][i], dist[friend_city][i])) {
            res = max(dist[your_city][i], dist[friend_city][i]);
            city = i;
        }
    }
    return city;    
}

void generalInfo() {
    cout << "If cities are not connected, then write -1. The distance for the same city is 0" << endl;
}

/*
Test Case
Number of cities = 5
0 2 -1 3 1
2 0 2 -1 -1
-1 2 0 3 1
3 -1 3 0 -1
1 -1 1 -1 0
Your city = 0
Friend's city = 2
Meetup point = 4
*/