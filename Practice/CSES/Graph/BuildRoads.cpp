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
 
#define MAXN 1000005
#define MOD 1000000007

vector<vi> graph(1000000);

void dfs(int n, vector<bool> & visited, unordered_set<int> & groups) {
    visited[n] = true;

    for (int u : graph[n]) {
        if (!visited[u])
            dfs(u, visited, groups);
    }
}

int main() {
    int n,m,a,b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    vector<bool> visited(graph.size());
    unordered_set<int> groups;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            groups.insert(i);
            dfs(i, visited, groups);
        }
    }

    vector<int> sol;
    for (auto x : groups) {
        sol.pb(x);
    }

    cout << (int)sol.size()-1 << endl;

    for (int i = 1; i < (int)sol.size(); i++) {
        cout << sol[0] << " " << sol[i] << endl;
    }
    return 0;
}