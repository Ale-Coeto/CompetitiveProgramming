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

bool check(vector<pair<ll, ll>> & nums, double & time) {
    double min_r = nums[nums.size()-1].first;
    double max_r = 0;

    for (int i = 0; i < nums.size(); i++) {
        min_r = min(min_r, nums[i].first + (nums[i].second*time));
        max_r = max(max_r, nums[i].first - (nums[i].second*time));
    }

    // cout << time << endl;
    return min_r >= max_r;
}
 
int main() { _

    ll n,a;
    vector<pair<ll,ll>> pts;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a;
        pts.pb({a,0});
    }

    ll min_v = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a;
        pts[i] = {pts[i].first, a};
        min_v = min(min_v, a);
    }

    sort(pts.begin(), pts.end());
    ll max_d = pts[pts.size()-1].first - pts[0].first;


    double left = 0;
    double right = (double)max_d/min_v;

    while (left < right && abs(left-right) > 1e-6) {
        double mid = left + (right-left)/2;

        if (check(pts, mid)) {
            right = mid;
        } else {
            left = mid+0.000001;
        }
    }

    cout << left << endl;
    
    return 0;
}