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

vector<ii> graph[MAXN];

void dijkstra(int V, int s) {
	vi dist(V+1, INF); dist[s] = 0; // INF = 1B to avoid overflow 
	priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s)); 
    
    while (!pq.empty()) { // main loop
	    ii front = pq.top(); 
        pq.pop(); // greedy: get shortest unvisited vertex 
	    int d = front.first, u = front.second;
	    
        if (d > dist[u]) continue; // this is a very important check 
	    for (int j = 0; j < (int)graph[u].size(); j++) {
	        ii v = graph[u][j]; // all outgoing edges from u 
	        
            if (dist[u] + v.second < dist[v.first]) {
	            dist[v.first] = dist[u] + v.second; // relax operation
	            pq.push(ii(dist[v.first], v.first));
	        } 
        } 
    } 
    // this variant can cause duplicate items in the priority queue
    for (int i = 1; i < V+1; i++) {
        cout << dist[i] << " ";
    }
}

int main() { _

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].pb({b,c});
        graph[b].pb({a,c});
    }

    dijkstra(n,1);



    return 0;
}