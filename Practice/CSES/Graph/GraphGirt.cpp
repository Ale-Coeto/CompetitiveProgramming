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

vector<vi> graph(100000);
vi visited(100000, -1);
vi cycles;

void dfs(int u, int parent) {
    visited[u] = parent;

    for (int x : graph[u]) {
        if (visited[x] == -1) {
            dfs(x,u);
        } else if (visited[x] != parent) {
            cycles.pb(x);
            cout << x << " ";
            visited[x] = u;
        }
    }
}

int cycleLength(int u) {
    int count = 1;
    int curr = visited[u];
    while (curr != u) {
        cout << curr << " ";
        curr = visited[curr];
        count++;
    }

    return count;
}
 
int main() { _
    int n,m,a,b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == -1) {
            
        }
    }

    if (cycles.empty()) {
        cout << -1 << endl;
        return 0;
    }

    cout << cycles.size();
    return 0;
    int ans = INT_MAX;
    for (int x : cycles) {
        ans = min(ans, cycleLength(x));
    }

    cout << ans << endl;

    return 0;
}