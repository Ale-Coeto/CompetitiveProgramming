#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
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
 
#define MAXN 1000005
#define MOD 1000000007

int n, m;
vi graph[MAXN];
vi visited(MAXN, -1);

 
void dfs(int u) {
    visited[u] = 1;

    for (int i = 0; i < (int)graph[u].size(); i++) {
        if (visited[graph[u][i]] == -1)
            dfs(graph[u][i]);
    }
}

int main() { _
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }


    int count = 0;
    queue<int> groups;

    for (int i = 1; i <= n; i++) {
        if (visited[i] == -1) {
            dfs(i);
            groups.push(i);
            count++;
        }
    }


    cout << count-1 << endl;
    while (groups.size() > 1) {
        cout << groups.front() << " ";
        groups.pop();
        cout << groups.front() << endl;
    }



return 0;
}