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

unordered_map<pair<ll,ll>, ll> dp; 

double binpow(double a, long long b) {
    // if (dp[{a,b}]) return dp[{a,b}];
    // cout << a << " " << b << " ";
    double res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }

    // cout << res << endl;
    return res;
}


void solve(ll & i, ll & f, ll & b) {
    long long ans = 0;
    ll init = i;
    double parth = double(double(b-1)/b);
    for (int n = 1; i > f; n++) {
        double power = binpow(parth,n);
        i = init * power;
        ans++;
    }

    cout << ans << endl;    

}
int main() { _
    int n;
    cin >> n;
    long long i,f,b;

    while (n--) {
        cin >> i >> f >> b;
        solve(i,f,b);
    }
    return 0;
}
