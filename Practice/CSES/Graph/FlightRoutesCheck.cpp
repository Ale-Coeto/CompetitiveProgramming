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
vector<bool> possible(1000000);

void bfs(int n, vector<bool> & visited, int & reached) {

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int front = q.front();
        if (possible[front]) {
            reached = -1;
            return;
        }
        q.pop();
        reached++;
        visited[front] = true;

        for (int x : graph[front]) {
            if (!visited[x]) {
                q.push(x);
            }
        }

    }

    // visited[n] = true;
    // if (possible[n] || reached == -1) {
    //     reached = -1;
    //     return;
    // }
    // reached++;
    // for (int x : graph[n]) {
    //     if (!visited[x]) {
    //         dfs(x, visited, reached);
    //     }
    // }
}
 
int main() { _
    int n,m,a,b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        graph[a].pb(b);
    }

    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n+1);
        int reach = 0;
        bfs(i, visited, reach);
        if (reach == n || reach == -1) {
            possible[i] = true;
        } else {
            cout << "NO" << endl;
            for (int j = 1; j <= n; j++) {
                if (visited[j] == 0) {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }

    cout << "YES" << endl;

    
    return 0;
}