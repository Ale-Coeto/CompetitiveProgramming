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

vector<vi> graph(100000);
vector<int> colors(100000);

bool bfs(int n) {
    queue<int> q;
    q.push(n);
    colors[n] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int x : graph[front]) {
            if (!colors[x]) {
                q.push(x);
                colors[x] = colors[front] == 1 ? 2 : 1;
            } else if (colors[x] == colors[front]) {
                cout << "IMPOSSIBLE" << endl;
                return false;
            }
        }
    }

    return true;
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
        bool attempt = true;
        if (!colors[i]) {
            attempt = bfs(i);
        }
        if (!attempt) return 0;
    }

    for (int i = 1; i <= n; i++) {
        cout << colors[i] << " ";
    }
    return 0;
}