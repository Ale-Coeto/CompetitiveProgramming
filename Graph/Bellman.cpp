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

vector<vii> graph;
vi dist; 
//Dijkstra for neg nums (it fails if negative weight cycle)
int bellmanFord(int V,int s) {
    
    for (int i = 0; i < V - 1; i++) // relax all E edges V-1 times
        for (int u = 0; u < V; u++) // these two loops = O(E), overall O(VE) 
            for (int j = 0; j < (int)graph[u].size(); j++) {
                ii v = graph[u][j]; // record SP spanning here if needed
                dist[v.first] = min(dist[v.first], dist[u] + v.second); // relax 
            }
}

bool checkNegativeCycles(int V) {
    bool hasNegativeCycle = false;
    for (int u = 0; u < V; u++) // one more pass to check
        for (int j = 0; j < (int)graph[u].size(); j++) {
            ii v = graph[u][j];
            if (dist[v.first] > dist[u] + v.second) // if this is still possible
                hasNegativeCycle = true; // then negative cycle exists! 
        }
    printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");
}

int main() { _

    int V;
    cin >> V;

    dist.assign(V, INF);
    int s = 1;
    dist[s] = 0;
    


    return 0;
}