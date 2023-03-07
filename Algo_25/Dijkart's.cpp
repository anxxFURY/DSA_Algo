//
// Created by Ani Hadagali on 27/02/23.
//

#include <iostream>
#include "algorithm"
#include "vector"
#include "list"
#include "utility"
#include "queue"
#include "set"
#include "unordered_map"
#include "map"
#include "string"
using namespace std;

#define ll int
#define prlong  int(n) cout << n;
#define loop(n) for( int i = 0; i < n; i++)
#define rloop(n) for(long long int j = n-1; j>0; j--)

class Dijk {
public:
    int n;
    vector<vector<pair<int,int>>> adj; // weighted graph

    Dijk(int n) {
        this->n = n;
        adj.resize(n);
    }

    void addEdge(int s, int d,int w) {
        adj[s].push_back(make_pair(d,w));
    }
// priority Queue
    vector<int> dijkstra(int S) {
        // {min-dist, node} heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);

        dist[S] = 0;
        pq.push({0,S});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(int i = 0; i < adj[node].size(); i++) {
                int edgeWeight = adj[node][i].second;
                int adjNode = adj[node][i].first;

                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }

            }
        }
        return dist;
    }

// Using sets

vector<int> dijkstrta_set(int S) {

        set<pair<int,int>> s;
        vector<int> dist(n,INT_MAX);
        dist[S] = 0;
        s.insert({0,S});

        while(!s.empty()) {
            auto it = *(s.begin());
            int node =it.second;
            int dis = it.first;
            s.erase(it);

            for(int i = 0 ; i < adj[node].size(); i++) {
                int edgeWeight = adj[node][i].second;
                int adjNode = adj[node][i].first;

                if(dis + edgeWeight < dist[adjNode]) {
                    // erase if previous value existed
                    if(dist[adjNode] != INT_MAX) {
                        s.erase({dist[adjNode],adjNode});
                    }

                    dist[adjNode] = dis+ edgeWeight;
                    s.insert({dist[adjNode],adjNode});
                }
            }
        }
    return dist;
    }

};


int main () {
    int n = 5;
    Dijk dijk(n+1);

    // Given graph

    // Shortest path form given source to all other nodes
    // Storing the shortest path in a vector
    dijk.addEdge(0,1,4);
    dijk.addEdge(0,2,4);
    dijk.addEdge(1,0,4);
    dijk.addEdge(1,2,2);
    dijk.addEdge(2,0,4);
    dijk.addEdge(2,1,2);
    dijk.addEdge(2,3,3);
    dijk.addEdge(2,4,1);
    dijk.addEdge(2,5,6);
    dijk.addEdge(3,2,3);
    dijk.addEdge(3,5,2);
    dijk.addEdge(4,2,1);
    dijk.addEdge(4,5,3);
    dijk.addEdge(5,3,2);
    dijk.addEdge(5,4,3);


    vector<int> res;
    res = dijk.dijkstra(0);
    res = dijk.dijkstrta_set(0);
    for(auto i : res) {
        cout << i << " ";
    }
    return  0;
}