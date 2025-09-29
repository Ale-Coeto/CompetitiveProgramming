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
 
vector<vi> tree(2000005);
vector<pair<long long, int>> best1(2000005, {-1,-1});
vector<pair<long long, int>> best2(2000005, {-1,-1});
vector<long long> dp_up(2000005,-1);

long long dfs_down(int n) {

    best1[n] = {0,0};

    priority_queue<pair<long long, int>> pq;
    for (int x : tree[n]) {
        if (best1[x].first == -1) {
            pq.push({dfs_down(x), x});
        }

    }

    if (pq.empty()) {
        best1[n] = {0,n};
        best2[n] = {0,n};
    } else if (pq.size() == 1) {
        best1[n] = pq.top();
        best1[n].first += 1;
        best2[n] = {0,n};
    } else {
        best1[n] = pq.top();
        best1[n].first += 1;
        pq.pop();
        best2[n] = pq.top();
        best2[n].first += 1;
    }

    return best1[n].first;
}

void dfs_up(int n, int p) {

    if (p == -1) {
        dp_up[n] = 0;
    } else {
        long long bestDown = best1[p].second == n ? best2[p].first + 1 : best1[p].first + 1;
        dp_up[n] = max(bestDown, dp_up[p]+1);
    }

    for (int x : tree[n]) {
        if (dp_up[x] == -1) {
            dfs_up(x, n);
        }
    }


}

int main() { _  
    int n,a,b;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        tree[a].pb(b);
        tree[b].pb(a);
    }

    dfs_down(1);
    dfs_up(1,-1);
    
    for (int i = 1; i <= n; i++) {
        cout << max(best1[i].first, dp_up[i]) << " ";
    }
    return 0;
}