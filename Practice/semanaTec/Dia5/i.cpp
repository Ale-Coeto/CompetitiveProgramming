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
 
void makeTree(vector<vi> & tree, unordered_map<int,int> & sums, vi & arr, map<int,vi> & paths) {
    queue<int> q;
    q.push(1);
    sums[1] = (0 ^ arr[0]);
    paths[1].pb(1);

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto x : tree[front]) {
            paths[x] = paths[front];
            paths[x].pb(x);
            sums[x] = sums[front] + (x-1 ^ arr[x-1]);
            q.push(x);
        }
    }
}


void solve(vector<vi> & tree, unordered_map<int,int> & sums, map<int,vi> & paths, int & a, int & b) {
    ll ans = 0;
    ll i = 0;
    ll j = 0;
    ll toSum = 0;

    while (i < paths[a].size() && j < paths[b].size() && paths[a][i] == paths[b][j]) {
        toSum = sums[paths[a][i]];
        if (i < paths[a].size() && j < paths[b].size() && paths[a][i] == paths[b][j]) {
        i++;
        j++;
        }
    }

    ans += toSum;
    if (paths[a].size() > i)
        ans += sums[paths[a][paths[a].size()-1]];
    if (i>=1) {
        if (i < paths[a].size()) {
            ans -= sums[paths[a][i-1]];
        } else if (i-2 >= 0) {
            ans -= sums[paths[a][i-2]];
        }
    }
    if (paths[b].size() > j)
        ans += sums[paths[b][paths[b].size()-1]];
    if (j>=1) {
        if (j < paths[b].size()) {
            ans -= sums[paths[b][j-1]];
        } else if (j-2 >= 0) {
            ans -= sums[paths[b][j-2]];
        }

    }

    cout << ans << endl;

}

int main() { _

    int t,n,a,b,q;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vi> tree(n+1);
        unordered_map<int,int> sums;
        vi arr;
        map<int,vi> paths;

        for (int i = 1; i < n; i++) {
            cin >> a >> b;
            tree[a].pb(b);
        }

        for (int i = 0; i < n; i++) {
            cin >> a;
            arr.pb(a);
        }
        makeTree(tree,sums,arr,paths);
        cin >> q;
        while (q--) {
            cin >> a >> b;
            solve(tree,sums,paths,a,b);
        }
    }
    return 0;
}