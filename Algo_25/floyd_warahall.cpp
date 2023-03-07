//
// Created by Ani Hadagali on 07/03/23.
//
#include <iostream>
#include "algorithm"
#include "vector"
#include "list"
#include "queue"
#include "utility"
#include "unordered_map"
#include "map"
#include "string"
using namespace std;

#define ll int
#define prlong  int(n) cout << n;
#define loop(n) for( int i = 0; i < n; i++)
#define rloop(n) for(long long int j = n-1; j>0; j--)

class Floyd {

    // Basic Graph Code
    // .....

    void shortest_path_floyd(vector<vector<int>> &matrix) {
        int n = matrix.size();

        for(int i =0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1) // Not reachable
                    matrix[i][j] = INT_MAX; // Dist infinity
                if(i == j)
                    matrix[i][j] == 0;
            }
        }

        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    matrix[i][j] = min (matrix[i][j],matrix[i][via]+matrix[via][j]);
                }
            }
        }

        // To check the Negative Cycles

        for(int i =0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(matrix[i][j] < 0)
                    cout << "Negative Cycle Exists";
            }
        }


    }
};

int main() {
    return 0;
}