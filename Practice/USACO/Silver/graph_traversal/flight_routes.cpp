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

void dfs(vector<vi> & graph, vector<bool> & visited, int n) {
    visited[n] = true;

    for (auto x : graph[n]) {
        if (!visited[x]) 
            dfs(graph, visited, x);
    }
}
 
int main() { _
    int n,m,a,b;

    cin >> n >> m;

    vector<vi> graph(n+1);
    vector<vi> graph2(n+1);
    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
        graph2[b].pb(a);
    }

    vector<bool> visited(n+1);
    vector<bool> visited2(n+1);

    dfs(graph, visited, 1);
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO" << endl;
            cout << 1 << " " << i << endl;
            return 0;
        }
    }

    dfs(graph2, visited2, 1);
    for (int i = 2; i <= n; i++) {
        if (!visited2[i]) {
            cout << "NO" << endl;
            cout << i << " " << 1 << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    
    return 0;
}