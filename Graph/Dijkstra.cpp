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
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10e5
#define MOD 1000000007
 
// Single source shortest paths

vector<vii> graph(MAXN);
vector<bool> visited(MAXN, false);
vector<int> path(MAXN);
vi dist(MAXN, LLONG_MAX);

// Careful with long long & infinite val
void dijkstra(int n) {
    priority_queue< ii, vii, greater<ii>> pq;
    pq.push({0,n});
    dist[n] = 0;

    while (!pq.empty()) {
        ii front = pq.top();
        pq.pop();
        if (visited[front.second]) continue;
        visited[front.second] = true;

        for (auto i : graph[front.second]) {
            if (dist[front.second] + i.second < dist[i.first]) {
                dist[i.first] = dist[front.second] + i.second;
                path[i.first] = front.second;
                pq.push({dist[i.first], i.first});
            }
        }

    }

}

int main() { _
    
    graph[1].pb({2,1});
    graph[1].pb({3,6});
    vii e = {{3,2},{4,1}};
    graph[2] = e;
    vii f = {{1,6},{2,2},{4,1}};
    graph[3] = f;
    vii x = {{2,1},{3,2},{5,5}};
    graph[4] = x;
    vii a = {{3,5},{4,5}};
    graph[5] = a;
    

    dijkstra(1);

    for (int i = 1; i < 6; i++) {
        cout << i << " : " ;
        cout << dist[i] << ", ";
        cout << path[i] << " / ";
    }

	return 0;
}

