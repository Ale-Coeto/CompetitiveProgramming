/*
    Edmonds-Karp Algorithm for Maximum Flow
    BFS-based implementation of Ford-Fulkerson
    O(V * E^2) time complexity
*/

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
#define pb push_back
#define INF 1000000000
typedef long long ll;
typedef vector<ll> vll;

int n;
vector<vector<ll>> capacity;
vector<vector<ll>> graph;

// To find augmenting paths
ll bfs(int source, int sink, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = -2;
    queue<pair<int, ll>> q;
    q.push({source, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (int next : graph[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == sink)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(int source, int sink) {
    ll flow = 0;
    vector<int> parent(n+1);
    ll new_flow = bfs(source, sink, parent);

    while (new_flow > 0) {
        flow += new_flow;
        int cur = sink;
        while (cur != source) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
        new_flow = bfs(source, sink, parent);
    }

    return flow;
}

int main() { 
    // Simple example: 4 nodes
    n = 4;
    capacity.assign(n, vector<ll>(n, 0));
    graph.assign(n, vll());
    
    // Add edges with capacities
    capacity[0][1] = 10; graph[0].pb(1); graph[1].pb(0);
    capacity[0][2] = 10; graph[0].pb(2); graph[2].pb(0);
    capacity[1][3] = 5;  graph[1].pb(3); graph[3].pb(1);
    capacity[2][3] = 10; graph[2].pb(3); graph[3].pb(2);
    
    cout << "Max flow: " << maxflow(0, 3) << endl;
    // Output: 15

    return 0;
}