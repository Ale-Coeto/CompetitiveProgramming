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

ll makePalindrome(vi nums, vector<vi> & dp, int & l, int  r) {
    ll moves = 0;
    ll left = l;
    ll right = r;
    // cout << l << " " << r << " ";


    while (left < right) {
        if (nums[left] == nums[right]) {
            left++;
            right--;
            // moves++;
            if (dp[left][right] != -1) {
                moves += dp[left][right];
                cout << "used";
                break;
            }
        } else if (nums[left] < nums[right]) {
            nums[left+1] = nums[left] + nums[left+1];
            left++;
            moves++;
        } else {
            nums[right-1] = nums[right] + nums[right-1];
            right--;
            moves++;
        }
    }
    dp[l][r] = moves;
    // cout << moves << " \n";
    return moves;
}

void solve(vi & nums) {
    if (nums.size() == 1) {
        cout << 0 << endl;
        return;
    }
    int size = nums.size();

    // vi temp(nums.begin()+1, nums.end()-1);
    int ans = 0;
    vector<vi> dp(nums.size(), vi(nums.size(),-1));

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size()-i; j++) {
            // vi temp(nums.begin()+j, nums.end()-i);/
            int right = size-1-i;
            ans += makePalindrome(nums, dp, j, nums.size()-1-i);
        }
    }

    cout << ans << endl;
}
 
int main() { _
    int t,n,a;
    scanf("%d",&t);
    // cin >> t;

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