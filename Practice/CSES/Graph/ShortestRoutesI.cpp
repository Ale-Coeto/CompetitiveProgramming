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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10e5
#define MOD 1000000007
 
vector<vii> graph(MAXN);
vector<bool> visited(MAXN, false);
vi dist(MAXN, LLONG_MAX);

void dijsktra(int n) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[n] = 0;
    pq.push({0,n});

    while (!pq.empty()) {
        ii u = pq.top();
        pq.pop();
        if (visited[u.second]) continue;
        visited[u.second] = true;

        for (auto v : graph[u.second]) {
            if (dist[u.second] + v.second < dist[v.first]) {
                dist[v.first] = dist[u.second] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

int main() { _
    int n, m, a, b, c;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b >> c;
        graph[a].pb({b,c});
    }

    dijsktra(1);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }

    return 0;
}