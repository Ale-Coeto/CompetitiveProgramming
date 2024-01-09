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

int n,m;
vector<u_int64_t> graph[MAXN];
vi visited(MAXN,-1);
int num = 1;
 
string bfs(u_int64_t u) {
    visited[u] = 0;
    queue<int> q;
    q.push(u);

    
    while(!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; i < (int)graph[f].size(); i++) {
            if (visited[f] == visited[graph[f][i]]) 
                return "IMPOSSIBLE";

            if (visited[graph[f][i]] == -1) {
                visited[graph[f][i]] = 1 - visited[f];
                q.push(graph[f][i]);
                
            } 
        }
    }

    return "";

}

int main() { _
    cin >> n >> m;

    while (m--) {
        u_int64_t a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);

    }

    string res;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == -1) {
            res = bfs(i);
            if (res == "IMPOSSIBLE") {
                cout << res;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        int n = visited[i];
        cout << ((n >= 1) ? 1 : 2) << " ";
    }

    return 0;
}