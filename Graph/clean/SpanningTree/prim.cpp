/*
    Kruskal algorithm for finding minimum spanning tree
    using union find
    O(n log(n))
*/

#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define pb push_back

vector<vector<ii>> graph;
vector<pair<int, ii>> minSpanningTree;
vector<bool> visited;

int prim(int start) {
    int cost = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0,start});

    while (!pq.empty()) {
        ii top = pq.top();
        pq.pop();
        int w = top.first;
        int u = top.second;
        
        if (visited[u]) continue;

        visited[u] = true;
        cost += w;

        for (ii x : graph[u]) {
            if (!visited[x.first]) {
                pq.push({x.second, x.first});
            }      
        }
    }

    return cost;
}
