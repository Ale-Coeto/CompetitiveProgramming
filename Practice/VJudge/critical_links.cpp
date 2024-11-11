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
#include <unordered_set>
#include <unordered_map>
 
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
 
#define MAXN 10
#define MOD 1000000007

vector<vii> graph(MAXN);
vi articulationVertex;
vi dfsLow, dfsNum, dfsParent;
int dfsCounter = 0, dfsRoot = 0, rootChildren = 0;

void findBridges(vector<vi> & graph, vii & bridges, int u) {
    dfsLow[u] = dfsNum[u] = dfsCounter++;

    for (int j = 0; j < (int)graph[u].size(); j++) {
        int v = graph[u][j];

        if (dfsNum[v] == 0) { // a tree edge
            dfsParent[v] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root
                findBridges(graph, bridges, v);

            // if (dfsLow[v] >= dfsNum[u]) // for articulation point
            //     articulationVertex[u] = true; 

            if (dfsLow[v] > dfsNum[u]) { // for bridge {}
                bridges.pb({u,v});
                // printf(" Edge (%d, %d) is a bridge\n", u, v);
            }

            dfsLow[u] = min(dfsLow[u], dfsLow[v]); // update dfsLow[u]

        } else if (v != dfsParent[u]) {// a back edge and not direct cycle
            dfsLow[u] = min(dfsLow[u], dfsNum[v]); // update dfsLow[u]
        }
    } 

}

 
int main() { _
    int n,a,b,t;
    char c;

    while (cin >> n) {

        vector<vi> graph(n+1);
        dfsNum.assign(n, 0); 
        dfsLow.assign(n, 0); 
        dfsParent.assign(n, 0); 
        vii bridges;

        for (int i = 0; i < n; i++) {
            cin >> a >> c >> t >> c;
            while (t--) {
                cin >> b;
                graph[a].pb(b);
            }
        }

        for (int i = 0; i < n; i++) {
            findBridges(graph, bridges, i);
        }

        cout << bridges.size() << " critical links" << endl;
        sort(bridges.begin(), bridges.end());

        for (auto x : bridges) {
            cout << min(x.first,x.second) << " - " << max(x.first, x.second) << endl;
        }
        cout << endl;
        // cin >> c;
    }

    return 0;
}