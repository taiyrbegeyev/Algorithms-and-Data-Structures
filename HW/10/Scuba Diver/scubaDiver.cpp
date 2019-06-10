/*
    Algorithms and Data Structures
    Spring 2019
    Assignment #10
    @file scubaDiver.cpp
    @author Taiyr Begeyev
    @version 1.0 02/05/19
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
#include <algorithm>
using namespace std;

int main() {
    // number of testcases
    int c;
    cin >> c;

    for (int i = 0; i < c; i++) {
        while(true) {
            // execute unless exception is thrown
            try {
                // volume of oxygen and nitrogen needed to compete task
                int t, a;
                cin >> t >> a;
                if (t < 1 || t > 21)
                    throw "t is out of range";
                if (a < 1 || t > 79)
                    throw "a is out of range";

                // number of cylinders
                int n;
                cin >> n;
                if (n < 1 || n > 1000)
                    throw "n is out of range";

                int oxygen[1000], nitrogen[1000], weight[1000];
                for (int i = 0; i < n; i++) {
                    // enter data for each cylinder
                    cin >> oxygen[i] >> nitrogen[i] >> weight[i];
                }


                // dynamic programming
                int dp[1000][22][80];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j <= t; j++) {
                        for (int k = 0; k <= a; k++) {
                            dp[i][j][k] = __INT_MAX__;
                            if (j == 0 && k == 0) {
                                dp[i][j][k] = 0;
                            }
                        }
                    }
                }

                for (int j = 0; j <= t; j++) {
                    for (int k = 0; k <= a; k++) {
                        if (j <= oxygen[0] && k <= nitrogen[0] && (j > 0 || k > 0)) {
                            dp[0][j][k] = weight[0];
                        }
                    }
                }

                for (int i = 1; i < n; i++) {
                    for (int j = 0; j <= t; j++) {
                        for (int k = 0; k <= a; k++) {
                            dp[i][j][k] = dp[i - 1][j][k];
                        
                            if (j <= oxygen[i] && k <= nitrogen[i])
                                dp[i][j][k] = min(dp[i][j][k], weight[i]);
                            else
                                dp[i][j][k] = min(dp[i][j][k], 
                                    weight[i] + dp[i-1][max(0,j-oxygen[i])][max(0,k-nitrogen[i])]);
                        }
                    }
                }

                // find the path
                int i = n - 1, x = t, y = a;
                vector<int> path;
                while(i >= 0 && (x > 0 || y > 0)) {
                    if (i == 0) {
                        path.push_back(i + 1);
                        break;
                    }
                    else if (dp[i][x][y] != dp[i-1][x][y]) {
                        x -= oxygen[i];
                        x = max(x, 0);
                        y -= nitrogen[i];
                        y = max(y, 0);
                        path.push_back(i + 1);
                        i--;
                    }
                    else {
                        i--;
                    }
                }
                reverse(path.begin(), path.end());

                // print min weight
                cout << dp[n - 1][t][a] << endl;

                // print the cylinders needed to complete task
                for (int x: path) {
                    cout << x << " ";
                }
                cout << endl;

                // if no exceptions are thrown, then get out of the infinite loop
                break;
            }
            catch(const char* e) {
                cerr << e << endl;
                cout << "Start Over!" << endl;
            }
        }
    }

    return 0;
}