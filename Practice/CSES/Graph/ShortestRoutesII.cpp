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
// #define INF 10000000000
 
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define RFOR(i, a, b) for(int i=int(a)-1; i>=int(b); i--)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(cont, it) for(typeof((cont).rbegin()) it = (cont).rbegin(); it != (cont).rend(); it++)
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 510
#define MOD 1000000007

ll INF = LLONG_MAX;
vector<vi> dp(MAXN, vi(MAXN, INF));

void floydWarshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

 
int main() { _

    int n,m,q,a,b;
    ll w;
    cin >> n >> m >> q;

    while (m--) {
        cin >> a >> b >> w;
    
        dp[a][b] = min(dp[a][b],w);
        dp[b][a] = min(dp[b][a],w);
    }

    floydWarshall(n);

    while (q--) {
        cin >> a >> b;
        if (a == b) 
            cout << 0 << endl;
        else 
            cout << (dp[a][b] >= INF ? -1 : dp[a][b]) << endl;
    }



    return 0;
}