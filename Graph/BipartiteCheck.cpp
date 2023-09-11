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
 
#define MAXN 10000
#define MOD 1000000007

vector<vii> graph(MAXN);
 
bool isBipartite(int n) {
    queue<int> q; 
    q.push(n);
    vi color(MAXN, INF); 
    color[n] = 0;

    bool isBipartite = true;
    int u = q.front(); 
    q.pop();

    for (int j = 0; j < (int)graph[u].size(); j++) {
        ii v = graph[u][j];
        if (color[v.first] == INF) { 
            color[v.first] = 1 - color[u]; 
            q.push(v.first);
        }

        else if (color[v.first] == color[u]) {
            isBipartite = false; 
            break; 
        }
 
    }  
}

int main() { _


    return 0;
}