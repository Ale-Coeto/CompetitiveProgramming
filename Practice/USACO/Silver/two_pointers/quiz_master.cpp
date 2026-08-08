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

map<int, vi> dp;
vi get_div(int & n, int & m) {
    if (!dp[n].empty())
        return dp[n];
    vi divisors;
    if (n <= m && n > 1)
        divisors.pb(n);
    for (int i = 2; i * i <= n && i <= m; i++) {
        if (n % i == 0) {
            divisors.pb(i);
            if (i != n/i && n/i <= m && n/i > 1) {
                divisors.pb(n/i);
            }
        }
    }
    dp[n] = divisors;
    return divisors;
}

bool can_rm(int & left, map<int,int> & mp) {
    for (auto x : dp[left]) {
        if (mp[x] <= 1) {
            return false;
        }
    }
    return true;
}

void solve(vi & nums, int & m) {
    sort(nums.begin(), nums.end());
    map<int,int> mp;
    int left = 0;
    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); i++) {
        vi div = get_div(nums[i], m);
        // cout << nums[i] << ": ";
        // for (auto x : div) {
        //     cout << x << " ";
        // }
        // cout << endl;
        for (auto x : div) {
            mp[x]++;
        }

        while (can_rm(nums[left], mp) && left < i) {
            // cout << i << "UES";
            for (auto x : dp[nums[left]]) {
                mp[x]--;
            }
            left++;
        }

        if (mp.size() == m-1) {
            // cout << left << " " << i<< endl;
            ans = min(ans,nums[i]-nums[left]);
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
 
int main() { _

    int t,n,a,m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vi nums;
        while (n--) {
            cin >> a;
            nums.pb(a);
        }
        dp.clear();
        solve(nums, m);
    }
    return 0;
}