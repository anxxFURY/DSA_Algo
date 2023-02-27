#include <iostream>
#include "algorithm"
#include "vector"
#include "list"
#include "utility"
#include "unordered_map"
#include "map"
#include "string"
using namespace std;

#define ll int
#define prlong  int(n) cout << n;
#define loop(n) for( int i = 0; i < n; i++)
#define rloop(n) for(long long int j = n-1; j>0; j--)

using namespace std;

class Graph {
private:
    bool** adj_matrix;    // Adjacency Matrix
    list<int> *adj_lists; // Adjacency List
    bool *visited; // DFS
    int num_vertices;

public:
    explicit Graph(int num_vertices) {
        this->num_vertices = num_vertices;
        adj_matrix = new bool * [num_vertices];

        for (int i = 0; i < num_vertices; ++i) {
            adj_matrix[i] = new bool [num_vertices];
            for (int j = 0; j < num_vertices; ++j) {
                adj_matrix[i][j] = false;
            }
        }
        // Adjacency List
        adj_lists = new list<int>[num_vertices];
        visited = new bool [num_vertices];
    }
    // Matrix Adjacency
    void addEdge(int i , int j) {
        adj_matrix[i][j] = true;
        adj_matrix[j][i] = true;
    }

    void removeEdge(int i, int j) {
        adj_matrix[i][j] = false;
        adj_matrix[i][j] = false;
    }

    void print() {
        for (int i = 0; i < num_vertices; ++i) {
            cout << i +1 << ": ";
            for (int j = 0; j < num_vertices; ++j) {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    // List adjacency

    void addEdge(vector<int> adj[],int s, int d) {
        adj[s].push_back(d);
        adj[d].push_back(s);
    }

    void print_list(vector<int> adj[], int v) {
        for (int i = 0; i < v ; ++i) {
            cout << "\nVertex " << i << " :";
            for (auto j: adj[i]) {
                cout << "->" << j;
            }
        }
    }

    // DFS
    void addEdge_DFS(int src, int des);
    void DFS(int vertex);
};

void Graph::addEdge_DFS(int src, int des) {
    adj_lists[src].push_front(des);
}
void Graph::DFS(int vertex) {
    visited[vertex] = true;
    list<int> adj_list = adj_lists[vertex];

    cout << vertex << " ";

    list<int>::iterator i;

    for (i = adj_list.begin(); i != adj_list.end(); ++i)
        if (!visited[*i])
            DFS(*i);

}

int main () {
    int n;
    cin >> n;


    vector<int> adj[n];
    Graph graph(n);

    // adjacency list:

    graph.addEdge(adj,)
  //  graph.print_list(adj,4);
    return 0;
}