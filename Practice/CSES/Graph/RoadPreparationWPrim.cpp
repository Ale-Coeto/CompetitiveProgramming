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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

vector<vector<ii>> graph;
vector<bool> visited;

ll prim(int start) {
    ll cost = 0;
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

int main() { _
    ll n,m,a,b,w;
    cin >> n >> m;

    graph.resize(n+1);
    visited.resize(n+1,false);

    while (m--) {
        cin >> a >> b >> w;
        graph[a].pb({b,w});
        graph[b].pb({a,w});
    }

    int components = 0;
    ll ans = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans = prim(i);
            components++;
        }
    }

    if (components == 1) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}