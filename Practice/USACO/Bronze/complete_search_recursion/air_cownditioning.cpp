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
ll ans = LLONG_MAX;
void bt(vector<pair<ii,int>> & cows, vector<vi> & ops, int index, vector<ll> & curr, ll curr_cost) {
    bool flag = true;
    if (index == ops.size()) {
        for (auto cow : cows) {
            if (!flag)
                break;
            for (int i = cow.first.first; i <= cow.first.second; i++) {
                if (curr[i] < cow.second) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            ans = min(ans, curr_cost);
        }
    }

    for (int i = index; i < ops.size(); i++) {
        for (int j = ops[i][0]; j <= ops[i][1]; j++) {
            curr[j] += ops[i][2];
        }
        bt(cows, ops, i+1, curr, curr_cost+(ll)ops[i][3]);
        for (int j = ops[i][0]; j <= ops[i][1]; j++) {
            curr[j] -= ops[i][2];
        }
    }
}
 
int main() { _

    int n,m,a,b,c, d;

    vector<pair<ii, int>> cows;
    vector<vi> ops;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        cows.pb({{a,b}, c});
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        ops.pb({a,b,c,d});
    }

    vector<ll> curr(101);
    bt(cows, ops, 0, curr, 0);
    cout << ans << endl;

    return 0;
}