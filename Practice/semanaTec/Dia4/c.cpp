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

int solve(int n, vector<vi> & tree, vi & colors, vi & blackNodes, vi & parent, int & qu) {
    queue<int> q;
    q.push(1);
    vector<int> bparent(n+1,-1);
    int groups = 0;
    if (colors[1] == 1) {
        bparent[1] = 1;
        groups++;
    }
    // unordered_set<int> groups;
    int invalidGroups = 0;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto x : tree[front]) {
            q.push(x);
            blackNodes[front] += colors[x];

            if (colors[x] == 1) {
                int par = parent[x];
                if (colors[par] == 1) {
                    bparent[x] = bparent[par];
                } else {
                    bparent[x] = x;
                    groups++;
                }
            }
        }

        if (blackNodes[front] > 2)
            invalidGroups++;
    }

    int a;
    while (qu--) {
            cin >> a;
            colors[a] = colors[a] == 1 ? 0 : 1;
            
            //vlack
            if (colors[a] == 1) {
                bool par;
                if (colors[parent[a]] == 1) {
                    bparent[a] = bparent[parent[a]];
                    blackNodes[parent[a]]++;
                    if (blackNodes[parent[a]] == 3) 
                        invalidGroups++;
                    par = true;
                } 

                bool flag = false;
                for (auto x : tree[a]) { //cada child
                    if (colors[x] == 1) {
                        bparent[x] = bparent[a];
                        groups--;
                        flag = true;
                    }
                }
                groups++;
                if (flag) groups--;
                if (!flag && !par) groups++;
                
            } else {
                int prev = blackNodes[parent[a]];
                blackNodes[parent[a]]--;
                if (prev > 2 && blackNodes[parent[a]] <= 2) invalidGroups--;

                bparent[a] = -1;

                bool flag = false;
                for (auto x : tree[a]) {
                    if (colors[x] == 1) {
                        bparent[x] = x;
                        groups++;
                        flag = true;
                    }
                }
                groups--;

                if (flag && colors[parent[a]] == 1) {
                    groups++;
                } 

            }

            if (groups == 1 && invalidGroups == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }

    return invalidGroups;
}
 
int main() { _
    int t,n,q,a,b;
    cin >> t;
    
    while (t--) {
        cin >> n >> q;
        vi colors(n+1);
        vector<vi> tree(n+1);
        vi parent(n+1);
        vi blackNodes(n+1);

        for (int i = 0; i < n; i++) {
            cin >> a;
            colors[i+1] = a;
        }

        for (int i = 0; i < n-1; i++) {
            cin >> a >> b;
            tree[a].pb(b);
            parent[b] = a;
        }

        solve(n,tree,colors,blackNodes,parent,q);
        
        cout << " \n";
    }


    return 0;
}
