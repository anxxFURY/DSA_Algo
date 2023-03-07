//
// Created by Ani Hadagali on 27/02/23.
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

class Bellman {
    int n;
    vector<vector<int>> adj; // weighted graph

    Bellman(int n) {
        this->n = n;
        adj.resize(n);
    }
    // Directed
    void addEdge(int s, int d,int w) {
        vector<int> arr = {s,d,w};
        adj.push_back(arr);
    }

    vector<int> bellman_ford(int S) {
        vector<int> dist(n,INT_MAX);
        dist[S] = 0;
        for(int i = 0; i < n-1; i ++) {
            for(auto it : adj) {
                int s = it[0];
                int d = it[1];
                int w = it[2];
                if(dist[s] != INT_MAX && dist[s] + w < dist[d]) {
                    dist[d] = dist[s] + w;
                }
            }
        }

        for(auto it : adj) {
            int s = it[0];
            int d = it[1];
            int w = it[2];

            if(dist[s] != INT_MAX && dist[s] + w < dist[d]) {
                return {-1};
            }
        }
        return dist;
    }
};


int main () {
    int n ;
    n = 6;
    
    return 0;
}