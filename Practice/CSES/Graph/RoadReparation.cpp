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
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

struct UnionFind {
    private: 
        vi parent;
        vi height; // Can use height of the tree as rank
        vi size;   // Or size (number of components in a set)
        int components;
        int largestSize;

    public:
        UnionFind(int n) {
            parent.resize(n+1,0);
            height.resize(n+1,0);
            size.resize(n+1,1);

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
            components = n;
            largestSize = 1;
        }

        // Find the root/representative of a node
        int find(int a) {
            if (parent[a] != a) {
                parent[a] = find(parent[a]);
            }
            return parent[a];
        }

        // Check if two nodes are connected
        bool isConnected(int a, int b) {
            return find(a) == find(b);
        }

        // Unite two nodes
        void unite(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);

            if (rootA != rootB) {
                // Always append the smaller tree to the larger one (could use height instead)
                if (size[rootA] < size[rootB]) {
                    swap(rootA, rootB);
                }
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
                largestSize = max(largestSize, size[rootA]);

                // // Unconmment this if using height
                // if (height[rootA] == height[rootB]) {
                //     height[rootA]++;
                // }
                components--;
            }
        }

        // Number of components/sets
        int getComponents() {
            return components;
        }

        // Size of the largest set
        int getLargestSize() {
            return largestSize;
        }

        // Get size of the set that a belongs to
        int getSize(int a) {
            int root = find(a);
            return size[root];
        }

};

vector<pair<ll,ii>> edges;
vector<pair<ll, ii>> minSpanningTree;

ll kruskal(UnionFind & uf) {

    sort(edges.begin(), edges.end());
    ll cost = 0;

    for (auto edge : edges) {
        int rootA = uf.find(edge.second.first);
        int rootB = uf.find(edge.second.second);

        if (rootA != rootB) {
            uf.unite(rootA, rootB);
            cost += edge.first;
            minSpanningTree.pb(edge);
        }

    }
    
    return cost;
}
 
int main() { _
    ll n,m,a,b,w;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b >> w;
        edges.pb({w,{a,b}});
    }

    UnionFind uf(n);
    ll ans = kruskal(uf);

    if (uf.getComponents() == 1) {
        cout << ans << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}