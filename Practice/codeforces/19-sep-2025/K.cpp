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
 
void solve(ll &x1, ll &x2, ll &x3, ll &x4) {
    ll ai, af;
    ll bi, bf;

    if (x1 < x3) {
        ai = x1;
        af = x2;
        bi = x3;
        bf = x4;
    } else {
        ai = x3;
        af = x4;
        bi = x1;
        bf = x2;
    }

    long long ans = 0;
    if (af >= bf) {
        ans = bf - bi;
    } else if (af < bf && af > bi) {
        ans = af - bi;
    }

    cout << ans << endl;
}

int main() { _
    int n;
    long long x1,x2,x3,x4;

    cin >> n;
    while (n--) {
        cin >> x1 >> x2 >> x3 >> x4;
        solve(x1, x2, x3, x4);
    }
    return 0;
}