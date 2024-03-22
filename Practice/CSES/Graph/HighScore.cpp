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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 2501
#define MOD 1000000007
 
vector<vii> graph(MAXN);
vi dist; 
//Dijkstra for neg nums (it fails if negative weight cycle) s = source
void bellmanFord(int V,int s) {
    dist.assign(V+1, -INF);
    dist[s] = 0;

    for (int i = 0; i < V - 1; i++) {// relax all E edges V-1 times
        for (int u = 1; u <= V; u++) {// these two loops = O(E), overall O(VE) 
            for (int j = 0; j < (int)graph[u].size(); j++) {
                ii v = graph[u][j]; // record SP spanning here if needed
                dist[v.first] = max(dist[v.first], dist[u] + v.second); // relax 
            }
        }
    }

}

bool checkNegativeCycles(int V) {

    for (int u = 1; u <= V; u++) // one more pass to check
        for (int j = 0; j < (int)graph[u].size(); j++) {
            ii v = graph[u][j];
            if (dist[v.first] < dist[u] + v.second) // if this is still possible
                return true; // then negative cycle exists! 
        }

    return false;

}

int main() { _
    ll n, m, a, b, c;
    cin >> n >> m;
    

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].pb({b,c});
    }

    bellmanFord(n, 1);

    if (checkNegativeCycles(n))
        cout << -1 << endl;
    else
        cout << dist[n] << endl;

    return 0;
}