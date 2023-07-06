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
 
int mst_cost, u, w, V;
vi taken; 
priority_queue<ii> pq; 
vector<vii> AdjList;

void process(int vtx) { 
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j];
        
        if (!taken[v.first]) 
            pq.push(ii(-v.second, -v.first));
    } 
}

int main() { _
    cin >> V;
    taken.assign(V, 0); 
    process(0); 
    mst_cost = 0;

    while (!pq.empty()) { 
        ii front = pq.top(); pq.pop();
        u = -front.second, w = -front.first; 
        if (!taken[u]) 
            mst_cost += w, process(u); 
    } 
    printf("MST cost = %d (Prim’s)\n", mst_cost);

return 0;
}