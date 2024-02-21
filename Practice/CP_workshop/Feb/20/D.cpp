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

void solve(int m, vector<int> &cost) {
    unordered_set<int> seen;
    unordered_map<int,int> indexes;
    

    for (int i = 0; i < cost.size(); i++) {
        int diff = m - cost[i];
        if (seen.count(diff) > 0) {
            cout << indexes[diff]+1 << " " << i+1 << endl;
            return;
        }

        seen.insert(cost[i]);
        indexes[cost[i]] = i;
    }
}
 
int main() { _

    int t, m, n, a;

    cin >> t;

    vi curr;

    while (t--) {
        cin >> m >> n;
        while (n--) {
            cin >> a;
            curr.pb(a);
        }

        solve(m, curr); 
        curr.clear();
    }

    return 0;
}