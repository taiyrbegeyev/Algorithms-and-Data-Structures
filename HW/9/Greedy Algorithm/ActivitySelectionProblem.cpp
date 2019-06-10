/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #8
    @file ActivitySelectionProblem.cpp
    @author Taiyr Begeyev
    @version 1.0 23/04/19
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
#include <algorithm>
#include <vector>
using namespace std;

struct Activity {
    int startTime;
    int finishTime;
};

/*
    @brief print the elements
*/
void print(vector<Activity> S) {
    int n = S.size();
    for (int i = 0; i < n; i++) {
        cout << "Activity " << i + 1<< ":" << endl;
        cout << S[i].startTime << " " << S[i].finishTime << endl << endl;
    }
}

/*
    @brief Greedy algortithm that solves the activity selection problem

    As our greedy choice we pick the activitu that has the latest start time

    @params the structure with our activities
    @return the structure with the solution
*/

vector <Activity> ActivitySelection(vector <Activity> S) {
    // this struct will contain the solution
    vector<Activity> ActivitySolution;
    
    int latestStartTime;
    int latestStartTimeIndex;
    while (!S.empty()) {
        latestStartTime = 0;
        // select activity with the latest start time
        for (int i = 0; i < S.size(); i++) {
            if (S[i].startTime > latestStartTime) {
                latestStartTime = S[i].startTime;
                latestStartTimeIndex = i;
            }
        }
        
        // check if it overlaps with activities in the ActivitySolution
        bool overLaps = false;
        for (int i = 0; i < ActivitySolution.size(); i++) {
            if (S[latestStartTimeIndex].finishTime > ActivitySolution[i].startTime) {
                overLaps = true;
            }
        }
        
        // push it to the ActivitySolution
        if (!overLaps)
            ActivitySolution.push_back(S[latestStartTimeIndex]);
        
        // delete this activity from S
        S.erase(S.begin() + latestStartTimeIndex);
    }
    return ActivitySolution;
}

int main() {
    vector <Activity> myActivities1, myActivities2, myActivities3;
    myActivities1 = {{1, 2}, {2, 3}, {4, 10}};
    myActivities2 = {
        {1, 4}, {3, 5},
        {0, 6}, {5, 7},
        {3, 8}, {5, 9},
        {6, 10}, {8, 11},
        {8, 12}, {2, 13}, {2, 14} 
    };
    myActivities3 = {
        {2, 14}, {2, 13},
        {8, 12}, {8, 11},
        {5, 9}, {3, 8}
    };

    myActivities1 = ActivitySelection(myActivities1);
    myActivities2 = ActivitySelection(myActivities2);
    myActivities3 = ActivitySelection(myActivities3);
    
    // print the result
    print(myActivities1);
    print(myActivities2);
    print(myActivities3);

    return 0;
}