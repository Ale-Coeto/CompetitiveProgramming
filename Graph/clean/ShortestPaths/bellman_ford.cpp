/*
    Algorithm for single source shortest paths
    Can solve for negative edges
    Can detect negative weight cycles but can't solve them
    O(nm) --> n = # of nodes, m = # of edges

    It goes through all of the edges n-1 times
*/


#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define pb push_back

// --- For graph as list of edges ---
vector<vi> edges;
vi distances;

// Do a last check to see if there is a negative cycle
bool hasNegativeCycleEdges() {
    vi copy = distances;
    for (auto edge : edges) {
        int a = edge[0];
        int b = edge[1];
        int w = edge[2];

        copy[b] = min(copy[b], copy[a]+w);
    }

    return copy != distances;
}

// n -> # of nodes, (a,b,w) -> from a to b with weight w
void bellmanFordEdges(int n, int source) {

    distances.resize(n+1, INT_MAX);
    distances[source] = 0;

    for (int i = 1; i <= n-1; i++) {
        for (auto edge : edges) {
            int a = edge[0];
            int b = edge[1];
            int w = edge[2];

            if (distances[a] != INT_MAX && distances[a] + w < distances[b]) {
                distances[b] = distances[a] + w;
            }
        }
    }

    // bool hasCycle = hasNegativeCycle();

}

// For graph as adj list
vector<vector<ii>> graph; // adjacency list: graph[a] = { {b, w}, ... }
// vi distances;

// Detect negative cycle
bool hasNegativeCycle(int n) {
    vi copy = distances;

    for (int a = 1; a <= n; a++) {
        if (copy[a] == INT_MAX) continue;
        for (auto [b, w] : graph[a]) {
            copy[b] = min(copy[b], copy[a] + w);
        }
    }

    return copy != distances;
}

// --- Bellman-Ford algorithm ---
void bellmanFord(int n, int source) {
    distances.assign(n + 1, INT_MAX);
    distances[source] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int a = 1; a <= n; a++) {
            if (distances[a] == INT_MAX) continue;

            for (auto [b, w] : graph[a]) {
                distances[b] = min(distances[b], distances[a] + w);
            }
        }
    }

    bool hasCycle = hasNegativeCycle(n);
    if (hasCycle) cout << "Negative cycle detected\n";
    else cout << "No negative cycle\n";
}

void runEdges() {
    // Test 1: Graph without negative cycle
    cout << "=== Test 1: No negative cycle ===" << endl;
    edges = {{1, 2, -1}, {1, 3, 4}, {2, 3, 3}, {2, 4, 2}, {4, 2, 1}};
    
    bellmanFordEdges(4, 1);
    
    cout << "Distances from node 1:" << endl;
    for (int i = 1; i <= 4; i++) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << ": INF" << endl;
        } else {
            cout << "Node " << i << ": " << distances[i] << endl;
        }
    }
    
    if (hasNegativeCycleEdges()) {
        cout << "Negative cycle detected!" << endl;
    } else {
        cout << "No negative cycle." << endl;
    }
    
    // Reset for next test
    edges.clear();
    distances.clear();
    
    // Test 2: Graph with negative cycle
    cout << "\n=== Test 2: With negative cycle ===" << endl;
    edges = {{1, 2, 1}, {2, 3, -3}, {3, 1, 1}};
    
    bellmanFord(3, 1);
    
    cout << "Distances from node 1:" << endl;
    for (int i = 1; i <= 3; i++) {
        if (distances[i] == INT_MAX) {
            cout << "Node " << i << ": INF" << endl;
        } else {
            cout << "Node " << i << ": " << distances[i] << endl;
        }
    }
    
    if (hasNegativeCycleEdges()) {
        cout << "Negative cycle detected!" << endl;
    } else {
        cout << "No negative cycle." << endl;
    }

}

void runAdj() {
    int n = 5;
    graph.assign(n + 1, {});

    // (a, b, w)
    graph[1].push_back({2, 4});
    graph[1].push_back({3, 2});
    graph[3].push_back({2, -1});
    graph[2].push_back({4, 2});
    graph[3].push_back({5, 3});

    bellmanFord(n, 1);

    for (int i = 1; i <= n; i++) {
        cout << "dist[" << i << "] = ";
        if (distances[i] == INT_MAX) cout << "INF\n";
        else cout << distances[i] << "\n";
    }
}

int main() { 
    runAdj();
    return 0;
}