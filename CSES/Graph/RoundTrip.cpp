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

vi graph[MAXN];
vi parent(MAXN,-1);
bool flag = false;

void printSol(int u, int target) {
    if (flag) return;
    stack<int> s;
    s.push(target);
    while (u != target) {
        if (u == parent[u]) break;
        s.push(u);
        u = parent[u];
    }
    s.push(u);
    cout << s.size() << endl;

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}

bool dfs(int u) {
    if (flag) return true;
    for (int i = 0; i < graph[u].size(); i++) {
        
        if (parent[graph[u][i]] == -1) {
            parent[graph[u][i]] = u;
            dfs(graph[u][i]);
        }

        else if (parent[u] != graph[u][i] && parent[u] != u){
            printSol(u,graph[u][i]);
            return flag = true;
        }
    }

    return false;
}



int main() { _
    int n, m;
    cin >> n >> m;

    while (m--) {
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

  

    for (int i = 2; i < n; i++) {
        if (parent[i] == -1) {
            parent[i] = i;
            dfs(i);
            if (flag) break;

        }
    }

    if (!flag) 
        cout << "IMPOSSIBLE";


    return 0;
}