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
 
vi dfs_num, dfs_low, S, visited; // global variables
int dfsNumberCounter = 0, numSCC = 0;
vector<vii> graph;
enum TYPE { VISITED, UNVISITED };

//Tarjan Algorithm for finding strongly connected components
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u] S.push_back(u); // stores u in a vector based on order of visitation visited[u] = 1;
    
    for (int j = 0; j < (int)graph[u].size(); j++) {
        ii v = graph[u][j];

        if (dfs_num[v.first] == UNVISITED)
            tarjanSCC(v.first);

        if (visited[v.first]) // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]); 
    }
    
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC printf("SCC %d:", ++numSCC); // this part is done after recursion 
        numSCC++;
        while (1) {
            int v = S.back(); 
            S.pop_back(); 
            visited[v] = 0; 
            cout << v << " ";
            if (u == v) break; 
        }
    }
    
}


int main() { _
    int v;
    cin >> v;

    dfs_num.assign(v, UNVISITED); 
    dfs_low.assign(v, 0); 
    visited.assign(v, 0); 
    
    for (int i = 0; i < v; i++)
        if (dfs_num[i] == UNVISITED) 
            tarjanSCC(i);

    return 0;
}