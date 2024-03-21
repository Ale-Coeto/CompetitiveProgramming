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
#define dbg(v) cout << "Line(" << _LINE_ << ") -> " << #v << " = " << (v) << endl;
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 
int main() { _

    int n;
    cin >> n;


    vector<pair<int, int> > v(n);

    vector<pair<int, int> > dp[2];

    for(int i = 0; i < n; i++){
        int x, h;
        cin >> x >> h;
        v[i] = {x, h};
    }

    dp[0].push_back({1, v[0].first});
    dp[1].push_back({1, v[0].first});

    for(int i = 1; i < n-1; i++){
        int f1 = v[i].first;
        int f2 = (v[i].first + v[i].second < v[i+1].first) ? v[i].first + v[i].second : v[i].first;

        int a1 = dp[0].back().second < v[i].first - v[i].second ? 1 : 0;

        int a2 = dp[1].back().second < v[i].first - v[i].second ? 1 : 0;

        int c1 = max(
            dp[0].back().first + a1,
            dp[1].back().first + a2
        );
        int t = max(dp[0].back().first, dp[1].back().first);
        int add = v[i].first + v[i].second < v[i+1].first ? 1 : 0;

        int c2 = t + add;

        dp[0].push_back({c1, f1});
        dp[1].push_back({c2, f2});
    }

    for(auto x : dp[0]){
        cout << x.first << " " << x.second << endl;
    }

    for(auto x : dp[1]){
        cout << x.first << " " << x.second << endl;
    }

    cout << max(dp[0].back().first, dp[1].back().first) << "\n";

    return 0;
}