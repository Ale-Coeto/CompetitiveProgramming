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

vector<vi> graph(1000001);
vi visited(1000001, -1);
int start = 1;
int ans = 0;

void bfs(int n) {

    queue<int> q;
    q.push(n);
    visited[n] = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (int x : graph[front]) {
            if (visited[x] == -1) {
                q.push(x);
                visited[x] = visited[front] + 1;
                if (visited[x] > ans) {
                    ans = visited[x];
                    start = x;
                }
            }
        }
    }
}
 
int main() { _
    int n,a,b;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    while (n--) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bfs(1);
    ans = 0;
    visited = vector<int>(1000001,-1);
    bfs(start);

    cout << ans << endl;

    return 0;
}