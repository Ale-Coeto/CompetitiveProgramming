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
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 
ll solve(vi & vec, int & target) {

    map<ll,ll> mp;
    ll ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        ll sub = vec[i] - target;

        if (sub == 0) 
            ans++;
            
        if (mp[sub])
            ans += mp[sub];

        mp[vec[i]]++;
    }

    return ans;
}
// 2 -1 3 5 -2
// 2 1 4 9 7

// -2 2 -2 2 7
// -2 0 -2 0 7

int main() { _
    int n,x,a;
    cin >> n >> x;

    vi vec(n);
    cin >> a;
    vec[0] = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        vec[i] = vec[i-1] + a;
    }

    cout << solve(vec, x) << endl;
    return 0;
}

// 7
// 2 -1 3 5 -2 1
// 2 1 4 9 7 8
// 2 2

// 2 -1 3 4 -6 5 2
// 2 1 4 8 

// -5 7 5
// -5 2 7

// -5 9

// 2 4 1 2 7
// 2 6 7 9 16