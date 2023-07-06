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
 
//Minumu Spanning Tree

class UnionFind { 
    private:
        vi p, rank; 
    public:
        UnionFind(int N) { 
            rank.assign(N, 0);
            p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; 
        }

        int findSet(int i) { 
            return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
        }

        bool isSameSet(int i, int j) { 
            return findSet(i) == findSet(j); 
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) { 
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) 
                p[y] = x; 
            else { 
                p[x] = y;

                if (rank[x] == rank[y]) 
                    rank[y]++; 
            }
        } } 
};

int main() { _
 
vector< pair<int, ii> > EdgeList; 
int V,E;
cin >> V >> E;
int u, v, w;

for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    EdgeList.push_back(make_pair(w, ii(u, v))); 
} 

sort(EdgeList.begin(), EdgeList.end()); 

int mst_cost = 0;

UnionFind UF(V); 
for (int i = 0; i < E; i++) { 
    pair<int, ii> front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)) { 
        mst_cost += front.first; 
        UF.unionSet(front.second.first, front.second.second); 
    } 
}

printf("MST cost = %d (Kruskal’s)\n", mst_cost);
return 0;
}