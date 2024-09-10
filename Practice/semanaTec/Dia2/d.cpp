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

ll gcd(ll a, ll b) { 
    return b == 0 ? a : gcd(b, a % b); 
}

ll lcm(ll a, ll b) { 
    return a * (b / gcd(a, b)); 
}

void solve(ll & x) {
    unordered_set<ll> s;
    string num = to_string(x);
    for (int i = 0; i < num.length(); i++) {
        if (num[i] - '0' != 0 && num[i] - '0' != 1)
            s.insert(num[i] - '0');
    }
    cout << s.size() << endl;
    ll common = 1;
    for (ll a : s) {
        // if (x % a != 0)
        if (common == 1) {
            common = a;
        } else
            common = lcm(common,a);
    }

    if (common == 1) {
        cout << x << endl;
        return;
    }

    ll div = x/common;
    ll ans = div*common;
    cout << common << " " << div << " " << ans << " ";
    while (ans < x) {
        ans += common;
    }
    cout << ans << endl;
    // cout << x << " " << common <<  " ";
    // ll ans = lcm(x,common);
    // cout << ans << " " << x + (ans/x) << endl;
}

int main() { _
    ll t,x;
    cin >> t;
    // cout << '7' - '0' << endl;
    while (t--) {
        cin >> x;
        solve(x);
    }

    return 0;
}