/*
    Algorithm for single source shortest paths
    Only for non negative edges
    O((V+e)logV)
*/

#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef long long ll;
#define pb push_back
#define MAXN 10e5


vector<vector<ii>> graph(MAXN); // graph[a] = (b,w)
vector<bool> visited(MAXN, false);
vi distances(MAXN, INT_MAX);
vi path(MAXN);

void dijkstra(int n) {
    priority_queue<ii, vii, greater<ii>> pq;
    pq.push({0, n});
    distances[n] = 0;

    while (!pq.empty()) {
        ii top = pq.top();
        ll dist = top.first;
        int u = top.second;
        pq.pop();
        
        if (visited[u]) continue;
        visited[u] = true;

        for (ii x : graph[u]) {
            if (distances[u] + x.second < distances[x.first]) {
                distances[x.first] = distances[u] + x.second;
                path[x.first] = u;
                pq.push({distances[x.first], x.first});
            }
        }
    }
}

int main() { 
graph[1].pb({2,1});
    graph[1].pb({3,6});
    vii e = {{3,2},{4,1}};
    graph[2] = e;
    vii f = {{1,6},{2,2},{4,1}};
    graph[3] = f;
    vii x = {{2,1},{3,2},{5,5}};
    graph[4] = x;
    vii a = {{3,5},{4,5}};
    graph[5] = a;
    

    dijkstra(1);

    for (int i = 1; i < 6; i++) {
        cout << i << " : " ;
        cout << distances[i] << ", ";
        cout << path[i] << "\n";
    }
    return 0;
}