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
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 

ll n;
vector<vector<ll>> capacity;
vector<vector<ll>> graph;
// vector<vi> results;
vector<unordered_set<int>> result;

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
        // vi path;
        while (cur != source) {
            // path.pb(cur);
            int prev = parent[cur];

            if (result[cur].find(prev) == result[cur].end()) {
                result[prev].insert(cur);
            } else {
                result[cur].erase(prev);
            }
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
        // path.pb(cur);
        // results.pb(path);
        new_flow = bfs(source, sink, parent);
    }

    return flow;
}

bool dfs(int u, int parent, vi & path) {
    path.pb(u);
    if (parent != -1) {
        result[parent].erase(u);
    }
    if (u == n) {
        return true;
    }


    for (auto x : result[u]) {
        return dfs(x, u, path);
    }

    return false;
}

void buildAns() {
    vi path;
    vector<vi> ans;

    while (dfs(1,-1, path)) {
        ans.pb(path);
        path = vi();
    }

    cout << ans.size() << endl;
    for (auto path : ans) {
        cout << path.size() << endl;
        for (auto x : path) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main() { _

    int m,a,b;

    cin >> n >> m;

    graph.assign(n+1, vi(0));
    capacity.assign(n+1, vi(n+1,0));
    result.assign(n+1, unordered_set<int>());

    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        capacity[a][b] = 1;
    }
    
    maxflow(1,n);

    buildAns();

    // cout << results.size() << endl;

    
    return 0;
}