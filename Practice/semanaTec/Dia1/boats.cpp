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

int getSize(vi & nums, int & sum) {
    int i = 0;
    int j = nums.size()-1;
    int ans = 0;
    while (i < j) {
        if (nums[i] + nums[j] == sum) {
            ans++;
            i++;
            j--;
        } else if (nums[i] + nums[j] > sum) {
            j--;
        } else {
            i++;
        }
    }
    // cout << sum << ans << " a\n";
    return ans;
}

void solve(vi & nums) {
    if (nums.size() <= 1) {
        cout << 0 << endl;
        return;
    }
    
    sort(nums.begin(), nums.end());
    int left = nums[0] + nums[1];
    int right = nums[nums.size()-1] + nums[nums.size()-2];
    int ans = getSize(nums,left);

    for (int i = left; i <= right; i++) {
        ans = max(ans, getSize(nums,i));
    }

    // while (left <= right) {
    //     int mid = left + (right-left)/2;
    //     int newA = getSize(nums,mid);
    //     if (newA > ans) {
    //         left = mid + 1;
    //         ans = newA;
    //     } else {
    //         right = mid - 1;
    //     }
    // }

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

}