#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
 
#define PI 3.141592653589793
#define EPS 0.000000001
#define INF 1000000000
 
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 100
#define MOD 1000000007

vector<vii> graph(MAXN);
vi articulationVertex;
vi dfsLow, dfsNum, dfsParent;
enum state {
    VISITED, UNVISITED
};
int dfsCounter = 0, dfsRoot = 0, rootChildren = 0;

// An ‘Articulation Point’ is defined as a vertex in a graph G whose removal disconnects G.
// a ‘Bridge’ is defined as an edge in a graph G whose removal disconnects G.


void articulationPointAndBridge(int u) {
    dfsLow[u] = dfsNum[u] = dfsCounter++; // dfs_low[u] <= dfsNum[u]
    for (int j = 0; j < (int)graph[u].size(); j++) {
        ii v = graph[u][j];

        if (dfsNum[v.first] == UNVISITED) { // a tree edge
            dfsParent[v.first] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
                articulationPointAndBridge(v.first);

            if (dfsLow[v.first] >= dfsNum[u]) // for articulation point
                articulationVertex[u] = true; // store this information first

            if (dfsLow[v.first] > dfsNum[u]) // for bridge
                printf(" Edge (%d, %d) is a bridge\n", u, v.first);

            dfsLow[u] = min(dfsLow[u], dfsLow[v.first]); // update dfsLow[u]

        } else if (v.first != dfsParent[u]) {// a back edge and not direct cycle
            dfsLow[u] = min(dfsLow[u], dfsNum[v.first]); // update dfsLow[u]
        }
    } 
}

int main() { _
    int V, m;
    int a,b;

    cin >> V >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].pb({b,0});
        graph[b].pb({a,0});
    }

    dfsNum.assign(V, UNVISITED); 
    dfsLow.assign(V, 0); 
    dfsParent.assign(V, 0); 
    articulationVertex.assign(V, 0);

    printf("Bridges:\n");
    for (int i = 0; i < V; i++) {
        if (dfsNum[i] == UNVISITED) {
            dfsRoot = i; rootChildren = 0; 
            articulationPointAndBridge(i);
            articulationVertex[dfsRoot] = (rootChildren > 1);
        } // special case
        
    }

    printf("Articulation Points:\n");
    for (int i = 0; i < V; i++) {
        if (articulationVertex[i])
            printf(" Vertex %d\n", i);
    }

    return 0;
}