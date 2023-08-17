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
 unordered_map<int, int> dp;

    int climbStairs(int n, int cur = 0) {
        if (cur == n) return 1;
        if (cur > n) return 0;

        cout << cur << " ";
        if (dp[cur]) {
            cout << "dp[" << cur << "] = " << dp[cur] << endl;
            return dp[cur];
        }
        cout << endl;
        dp[cur] = climbStairs(n,cur+1) + climbStairs(n,cur+2);
        return dp[cur];

        return dp[0];
    }

    stack<pair<int,int>> s;

    int check = 0;
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;

        int left = 0;
        int right = left+2;
        int curMax = height[0];
        int begin = 0;

        vector<int> res(height.size(), 0);
        while (right < height.size()) {
            cout << left << " " << right << endl;

            while (height[left+1] > height[left]){
                left++;
                curMax = height[left];
                right += 1;
                cout << left << " " << right << endl;
            }

            if (right >= height.size()) continue;
            
            if (height[right] >= curMax) {
                curMax = height[right];
                for (int i = left+1; i < right; i++) {
                    res[i] = height[left]-height[i];
                    if (res[i] < 0) res[i] = 0;
                }
                left = right;
                right += 2;
                begin = right;
            } else {
                if (height[right] > height[right-1]){
                    int prev = s.empty() ? left :  s.top().second;
                    s.push({prev,right});
                    check = right;
                    cout << "check " << prev << " " << check << endl;
                }
                right++;
            }

        }

        while(!s.empty()) {
            int prev = s.top().first;
            int cur = s.top().second;
            s.pop();
            for (int i = prev+1; i < cur && i > begin; i++) {
                res[i] = height[cur]-height[i];
                if (res[i] < 0) res[i] = 0;
            }
        }
        // for (int i = left+1; i < check; i++) {
        //     res[i] = height[check]-height[i];
        //     if (res[i] < 0) res[i] = 0;
        //     else
        //        cout << "s " << i << ' ' << res[i] << endl;
        // }

    int ans = 0;
        for (auto i : res) {
            cout << i << " ";
            ans += i;
        }

        return ans;
    }

int main() { _
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    //1 1 6 9 6 
   cout << trap(v);
return 0;
}