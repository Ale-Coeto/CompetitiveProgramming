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
 
#define MAXN 10
#define MOD 1000000007
 
void solve(int t, int n) {
    vi graph[n+2];
    int a, x;

    for (int i = 1; i < n; i++) {
        cin >> a;
        while (a--) {
            cin >> x;
            graph[i].push_back(x);
        }

    }

    queue<ii> q;
    vector<bool> visited(n+2, false);
    set<int> ans;

    for (auto i : graph[1]) {
        q.push({i, i});
        visited[i] = true;
    }

    visited[1] = true;

    while (!q.empty()) {
        ii front = q.front();
        // cout << front.first << " " << front.second << endl;
        q.pop();

        for (auto i : graph[front.first]) {
            if (i == n) {
                ans.insert(front.second);
                // cout << front.second << "f  \n";
                continue;
            }

            if (!visited[i]) {
                visited[i] = true;
                q.push({i, front.second});
            }
        }
    }

    cout << ans.size() << endl;
}

int main() { _
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        solve(t, n);
    }

    return 0;
}