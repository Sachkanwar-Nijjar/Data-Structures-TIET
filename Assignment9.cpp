A graph G is defined as a pair (V, E) where V is a set of nodes/vertices and E is a set of edges connecting
pairs of vertices. Graphs may be directed or undirected and may have weighted or unweighted edges.
They can be represented using an adjacency matrix, adjacency list, or edge list.
Write a program to implement the following graph algorithms:

========================================================================BASIC STRUCTURE======================================================================================

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int no_of_vertices;
    bool isDirected;
    vector<vector<int>> adjmat;  

public:
    Graph(int vertices, bool directed = false) {
        no_of_vertices = vertices;
        isDirected = directed;
        adjmat.resize(no_of_vertices, vector<int>(no_of_vertices, 0));
    }

    void addVertex() {
        no_of_vertices++;

        adjmat.push_back(vector<int>(no_of_vertices, 0));

        for (int i = 0; i < no_of_vertices - 1; i++) {
            adjmat[i].push_back(0);
        }

        cout << "Vertex " << no_of_vertices - 1 << " added successfully!\n";
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= no_of_vertices || v >= no_of_vertices) {
            cout << "Invalid vertex number!\n";
            return;
        }

        adjmat[u][v] = 1;
        if (!isDirected)
            adjmat[v][u] = 1;

        cout << "Edge added between " << u << " and " << v << endl;
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < no_of_vertices; i++) {
            for (int j = 0; j < no_of_vertices; j++) {
                cout << adjmat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4, false); 
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.display();
    g.addVertex();
    g.addEdge(4,1);
    g.display();

    return 0;
}
================================================================================================================================================================
1. Breadth First Search (BFS)
    #include <iostream>
    #include <vector>
    #include <queue>
    using namespace std;

  class Graph {
  private:
    int no_of_vertices;
    bool isDirected;
    vector<vector<int>> adjmat; 

  public:
    Graph(int vertices, bool directed = false) {
        no_of_vertices = vertices;
        isDirected = directed;
        adjmat.resize(no_of_vertices, vector<int>(no_of_vertices, 0));
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= no_of_vertices || v >= no_of_vertices) {
            cout << "Invalid vertex number!\n";
            return;
        }
        adjmat[u][v] = 1;
        if (!isDirected)
            adjmat[v][u] = 1;
        cout << "Edge added between " << u << " and " << v << endl;
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < no_of_vertices; i++) {
            for (int j = 0; j < no_of_vertices; j++) {
                cout << adjmat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void BFS(int start) {
        if (start < 0 || start >= no_of_vertices) {
            cout << "Invalid starting vertex!\n";
            return;
        }

        vector<bool> visited(no_of_vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS traversal starting from vertex " << start << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            for (int j = 0; j < no_of_vertices; j++) {
                if (adjmat[current][j] == 1 && !visited[j]) {
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5, false); 
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.display();
    g.BFS(0);

    return 0;
}

=============================================================================================================================================================

2. Depth First Search (DFS)

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int no_of_vertices;
    bool isDirected;
    vector<bool> visited;
    vector<vector<int>> adjmat; 
    

public:
    Graph(int vertices, bool directed = false) {
        no_of_vertices = vertices;
        isDirected = directed;
        adjmat.resize(no_of_vertices, vector<int>(no_of_vertices, 0));
        visited.resize(no_of_vertices, false); 
    }

    void addEdge(int u, int v) {
        if (u < 0 || v < 0 || u >= no_of_vertices || v >= no_of_vertices) {
            cout << "Invalid vertex number!\n";
            return;
        }
        adjmat[u][v] = 1;
        if (!isDirected)
            adjmat[v][u] = 1;
        cout << "Edge added between " << u << " and " << v << endl;
    }

    void display() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 0; i < no_of_vertices; i++) {
            for (int j = 0; j < no_of_vertices; j++) {
                cout << adjmat[i][j] << " ";
            }
            cout << endl;
        }
    }
    void dfs(int start) {
        cout<<start<<" ";
        visited[start]=1;
        for(int j=0;j<no_of_vertices;j++){
            if(adjmat[start][j]==1 && !visited[j]){
                dfs(j);
            }
        }
        
    }
    void DFS(int start) { 
        cout<<endl<<"DFS of given graph is "<<endl;
        dfs(start);
    }
};

int main() {
    Graph g(7, false); 
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,0);
    g.addEdge(2,4);
    g.addEdge(3,0);
    g.addEdge(3,2);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(4,6);
    g.display();
    g.DFS(4);

    return 0;
}

=============================================================================================================================================================
3. Minimum Spanning Tree (Kruskal and Prim)



4. Dijkstra's Shortest Path Algorithm

#include <iostream>
#include <vector>
#include <utility>   // for std::pair
#include <limits>    // for std::numeric_limits

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // adjacency list: adj[u] = vector of (neighbor, weight)
    vector<vector<pair<int,int>>> adj(n);

    cout << "Enter edges (u v w) with 0-based nodes:\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // assuming 0-based input for u and v
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove this line if graph is directed
    }

    int source;
    cout << "Enter source vertex (0 to " << n-1 << "): ";
    cin >> source;

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);

    dist[source] = 0;

    // Dijkstra O(n^2) without heap
    for (int i = 0; i < n; i++) {
        // 1. Pick the unvisited node with minimum dist[]
        int u = -1;
        int minDist = INF;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }

        // No more reachable vertices
        if (u == -1) break;

        visited[u] = true;

        // 2. Relax edges from u
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "To " << i << ": ";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}

============================================================================================================================================================

5. Floyd–Warshall (All-Pairs Shortest Path)
#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main() {
    int n = 4;
    vector<vector<long long>> dist(n, vector<long long>(n, INF));

    // distance to self = 0
    for (int i = 0; i < n; i++) dist[i][i] = 0;

    auto addEdge = [&](int u, int v, long long w) {
        dist[u][v] = min(dist[u][v], w); // handle multi edges
        dist[v][u] = min(dist[v][u], w); // if undirected
    };

    addEdge(0, 1, 3);
    addEdge(0, 2, 5);
    addEdge(1, 2, 1);
    addEdge(1, 3, 4);
    addEdge(2, 3, 2);

    // Floyd–Warshall
    for (int k = 0; k < n; k++) {          // intermediate
        for (int i = 0; i < n; i++) {      // source
            for (int j = 0; j < n; j++) {  // destination
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    cout << "All-pairs shortest distances:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] >= INF/2) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}



=================================================================================================================================================

6. Disjoint Sets (Union–Find / DSU)

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;   // each node is its own leader
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]); 
        // path compression: directly connect to leader
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a != b) {
            // union by size
            if (size[a] < size[b])
                swap(a, b);

            parent[b] = a;
            size[a] += size[b];
        }
    }
};




