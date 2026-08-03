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
 
ll check(vi & nums) {
    ll ans = 0;
    for (int i = 1; i < nums.size(); i+=2) {
        ans += abs(nums[i] - nums[i-1]);
    }
    return ans;
}

int main() { _
    int n,a;
    cin >> n;
    n*=2;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    ll ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int ni = nums[i];
        nums.erase(nums.begin()+i);
        for (int j = 0; j < nums.size(); j++) {
            int nj = nums[j];
            nums.erase(nums.begin()+j);
            ans = min(ans, check(nums));
            nums.insert(nums.begin()+j, nj);
        }
        nums.insert(nums.begin()+i, ni);
    }

    cout << ans << endl;
    return 0;
}