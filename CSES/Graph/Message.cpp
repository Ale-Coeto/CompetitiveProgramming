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
 
#define MAXN 1000000
#define MOD 1000000007

vi graph[MAXN];
vi visited(MAXN,-1);
vi path(MAXN);
int n, m;
 
bool bfs(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    path[u] = 0;
   

    while(!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 0; i < graph[f].size(); i++) {
            int next = graph[f][i];
            if (visited[next] == -1) {
                q.push(next);
                visited[next] = 1;
                path[next] = f;
            }
        }
        if (f == n) return true;
    }
    return false;
}

int main() { _

 cin >> n >> m;

 for (int i = 0; i < m; i++) {
    int a,b;

    cin >> a >> b;
    graph[a].pb(b);
    graph[b].pb(a);

 }

bool res = bfs(1);

if (!res) 
    cout << "IMPOSSIBLE";
else {
    vi reverseP;
    int num = n;
    reverseP.pb(n);

    while (num != 1) {
        num = path[num];
        reverseP.pb(num);
    }

    reverse(reverseP.begin(),reverseP.end());
    cout << reverseP.size() << endl;
    for (int i : reverseP) {
        cout << i << " ";
    }
}





return 0;
}