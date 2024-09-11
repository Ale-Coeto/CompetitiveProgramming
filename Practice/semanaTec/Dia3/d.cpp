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

void solve(vi & nums) {
    int prev = nums[0];
    int ans = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != prev) {
            if (i == nums.size()-1) {
                ans = nums.size()-1;
            } else if (prev == nums[i+1]) {
                ans = i;
            } else {
                ans = 0;
            }
            break;
        }
    }

    cout << ans+1 << endl;
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