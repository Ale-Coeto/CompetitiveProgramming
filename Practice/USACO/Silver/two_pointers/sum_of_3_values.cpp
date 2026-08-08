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
 
int main() { _
    ll n,target,a;
    vector<pair<int, int>> nums;
    // vi nums;

    cin >> n >> target;

    for (int i = 0; i < n; i++) {
        cin >> a;
        nums.pb({a,i});
        // nums.pb(a);
    }

    sort(nums.begin(), nums.end());

    bool found = false;
    set<int> sol;
    
    for (int i = 0; i < n; i++) {
        int t = target - nums[i].first;
        ii temp = nums[i];
        nums.erase(nums.begin()+i);

        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            if (t == nums[left].first + nums[right].first) {
                sol.insert(temp.second+1);
                sol.insert(nums[left].second+1);
                sol.insert(nums[right].second+1);

                for (auto x : sol) {
                    cout << x << " ";
                }
                cout << endl;
                break;
            } else if (nums[left].first+nums[right].first > t) {
                right--;
            } else {
                left++;
            }
        }
        if (!sol.empty())
            break;
        nums.insert(nums.begin()+i, temp);
    }

    if (sol.empty()) {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}