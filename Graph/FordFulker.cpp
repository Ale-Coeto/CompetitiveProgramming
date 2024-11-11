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

const int N = 210; //Max num of nodes

int g[N][N]; //Capacity of each edge
int parent[N];

//Used to find an augmenting path from the start node to the end node in the residual graph.
bool bfs(int start, int end) {
  bool visited[N];
  memset(visited, 0, sizeof(visited));

  queue<int> q;
  q.push(start);
  visited[start] = true;
  parent[start] = -1;

  while(not q.empty()) {
    int u = q.front();
    q.pop();

    for(int v = 0; v <= end; ++v) {
      if(visited[v] or g[u][v] <= 0)
        continue;

      q.push(v);
      parent[v] = u;
      visited[v] = true;
    }
  }

  return visited[end];
}

int ford_fulker(int start, int end) {
  int u, v;
  int max_flow = 0;

  while(bfs(start, end)) {
    int path_flow = INT_MAX;

    for(v = end; v != start; v = parent[v]) {
      u = parent[v];
      path_flow = min(path_flow, g[u][v]);
    }

    for(v = end; v != start; v = parent[v]) {
      u = parent[v];
      g[u][v] -= path_flow;
      g[v][u] += path_flow;
    }

    max_flow += path_flow;
  }

  return max_flow;
}

int main() { _

//resp[r][c][0] = min()
    return 0;
}