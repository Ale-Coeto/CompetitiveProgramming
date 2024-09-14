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
 
int main() { _
    unordered_map<int,int> mp;
    vii nums;
    vii ans;
    
    int n,a;
    cin >> n;

    cin >> a;
    int m = a;

    for (int i = 2; i <= n; i++) {
        cin >> a;
        nums.pb(make_pair(a,i));
    }


    std::sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    int right = 0;
    while (m--) {
        ans.pb(make_pair(1,nums[right++].second));
        if (right >= nums.size()) {
            break;
        }
    }

    bool done = right >= nums.size();
    for (int i = 0; i < right && !done; i++) {
        while (nums[i].first--) {
            if(!done) {
                ans.pb(make_pair(nums[i].second, nums[right++].second));
                if (right >= nums.size()) {
                    done = true;
                    break;
                }
            } else {
                ans.pb(make_pair(nums[i].second,1));
            }
        }
    }


    if (done) {
        cout << ans.size() << endl;
        for (auto x : ans) {
            cout << x.first << " " << x.second << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}