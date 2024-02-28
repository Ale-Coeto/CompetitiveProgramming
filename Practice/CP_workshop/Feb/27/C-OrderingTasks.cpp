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
 
#define MAXN 10
#define MOD 1000000007
 
void dfs(vector<vi> &graph, vector<bool> &visited, stack<int> &ans, int u) {
    visited[u] = true;

    for (int i = 0; i < graph[u].size(); i++) {
        if (!visited[graph[u][i]]) 
            dfs(graph, visited, ans, graph[u][i]);
    }

    ans.push(u);
}

void solve(int n, int m) {
    int a, b;
    vector<vi> graph(n);
    vector<bool> visited(n, false);
    stack<int> ans;

    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
        visited[b] = false;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(graph, visited, ans, i);
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

    cout << endl;
    
}

int main() { _

    int n, m;

    while (cin >> n >> m) {
        if (n == 0 || m == 0) break;
        solve(n, m);
        
    }

    return 0;
}