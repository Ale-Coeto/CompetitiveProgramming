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
 
vector<vi> graph(1000000);
vector<bool> visited(1000000, false);
vector<bool> recStack(1000000, false);
vi sol;
bool impossible = false;

bool hasCycle(int n) {
    visited[n] = true;
    recStack[n] = true;

    for (auto x : graph[n]) {
        if (!visited[x]) {
            if (hasCycle(x)) {
                return true;
            }
        } else if(recStack[x]) {
            return true;
        }   
    }

    recStack[n] = false;
    return false;
}

void dfs(int n) {
    visited[n] = true;

    for (auto x : graph[n]) {
        if (!visited[x]) {
            dfs(x);
        }
    }

    sol.pb(n);
}

int main() { _
    int n,m,a,b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && hasCycle(i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    visited = vector<bool>(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    reverse(sol.begin(), sol.end());

    for (auto x : sol) {
        cout << x << " ";
    }

    return 0;
}