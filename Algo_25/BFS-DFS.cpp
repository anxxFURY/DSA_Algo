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

#define ll int
#define prlong  int(n) cout << n;
#define loop(n) for( int i = 0; i < n; i++)
#define rloop(n) for(long long int j = n-1; j>0; j--)

class Graph {
public:
    vector<vector<int>> adj;
    int n;
    vector<bool> vis_DFS,vis_BFS;
    Graph(int n) {
        this->n = n;
        adj.resize(n);
        vis_BFS.resize(n, false);
        vis_DFS.resize(n, false);
    }
    void addEdge(int s, int d) {
        adj[s].push_back(d);
    }

    vector<int> bfs(int st_node) {
        vis_BFS[st_node] = true;
        queue<int> q;
        q.push(st_node);
        vector<int> bf;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            bf.push_back(node);

            for(auto i : adj[node]) {
                if(!vis_BFS[i]) {
                    vis_BFS[i] = true;
                    q.push(i);
                }
            }
        }

        return bf;
    }


    void dfs(int node, vector<bool> vis, vector<int> &ls) {
        vis[node] = true;
        ls.push_back(node);

        for(auto i : adj[node]) {
            if(!vis[i]) {
                dfs(i,vis,ls);
            }
        }
    }

    vector<int> dfs_main(int st_node) {
        vector<int> ls ;
        dfs(st_node,vis_DFS,ls);
        return ls;
    }


};


int main () {
    vector<bool> flag;
    if(flag[0])
        int x = 2;

    int n = 11;
    Graph graph(n);

    // Graph Given

    graph.addEdge(1,6);
    graph.addEdge(1,7);
    graph.addEdge(1,2);
    graph.addEdge(2,1);
    graph.addEdge(2,3);
    graph.addEdge(3,2);
    graph.addEdge(3,4);
    graph.addEdge(4,3);
    graph.addEdge(4,5);
    graph.addEdge(5,4);
    graph.addEdge(6,1);
    graph.addEdge(7,1);
    graph.addEdge(7,8);
    graph.addEdge(8,9);
    graph.addEdge(8,10);
    graph.addEdge(8,7);
    graph.addEdge(9,8);
    graph.addEdge(10,8);

    vector<int> res;
    res = graph.bfs(4);
    for(auto i : res) {
        cout << i << " ";
    }
    cout << "\n";
    res = graph.dfs_main(1);
    for(auto i : res) {
        cout << i << " ";
    }


    return 0;
}