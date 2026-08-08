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

void solve(vi & nums) {
    vi pre(nums.size()+2, LLONG_MIN);
    vi pos(nums.size()+2, LLONG_MIN);

    for (int i = 1; i <= nums.size(); i++) {
        ll pre_curr = nums[i-1] - (nums.size() - i);
        pre[i] = max(pre[i-1], pre_curr);
        ll pos_curr = nums[nums.size()-i] - (nums.size()-i);
        pos[nums.size()-i] = max(pos[(nums.size()-i)+1], pos_curr);
        // cout << pre[i] << " " << pos[i] << endl;
        // cout << pos_curr << " " << pos[i] << endl;
    }

    ll ans = 0;
    for (int i = 2; i < nums.size(); i++) {
        // cout << pos[i] << " ";
        // cout << nums[i-1] << " " << pre[i-1] << " " << pos[i+1] << " " << nums.size()-1 << endl;
        ans = max(ans, nums[i-1] + pre[i-1] + pos[i] + (ll)(nums.size()-1));
    }
    cout << ans << endl;
}
 
int main() { _
    int t,n,a;
    cin >> t;
    while (t--) {
        cin >> n;
        vi nums;
        while (n--) {
            cin >> a;
            nums.pb(a);
        }
        solve(nums);
    }

    return 0;
}