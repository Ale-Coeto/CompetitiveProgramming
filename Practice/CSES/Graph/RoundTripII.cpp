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
vi recStack(1000000,-1);

int solve(int u, int parent) {
    visited[u] = true;
    recStack[u] = parent;

    for (auto x : graph[u]) {
        if (!visited[x]) {
            int ans = solve(x,u);
            if (ans != -1) {
                return ans;
            }
        } else if (recStack[x] != -1) {
            recStack[x] = u;
            return x;
        }
    }

    recStack[u] = -1;
    return -1;
}

void printSol(int u) {
    int curr = recStack[u];
    vi solution;

    solution.pb(u);

    while (u != curr) {
        solution.pb(curr);
        curr = recStack[curr];
    }

    solution.pb(u);
    reverse(solution.begin(), solution.end());

    cout << (int)solution.size() << endl;
    for (auto x : solution) {
        cout << x << " ";
    }
}

int main() { _
    int n,m,a,b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
    }

    int ans = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ans = solve(i, 0);
            if (ans != -1) {
                printSol(ans);
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}