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
    int n,k,a;
    cin >> n >> k;

    vi nums;
    while (n--) {
        cin >> a;
        nums.pb(a);
    }

    vi scores;
    set<int> s;
    while (k--) {
        cin >> a;
        scores.pb(a);
        s.insert(a);
    }

    
    vi pref(nums.size() + 1, 0);
    FOR(i, 0, nums.size()) {
        pref[i + 1] = pref[i] + nums[i];
    }

    set<int> prefSums(pref.begin(), pref.end());
    set<int> ans;

    for (int start : scores) {
        for (int sum : pref) {
            ans.insert(start - sum);
        }
    }

    set<int> good;
    for (int candidate : ans) {
        bool ok = true;
        for (int target : scores) {
            if (prefSums.find(target - candidate) == prefSums.end()) {
                ok = false;
                break;
            }
        }
        if (ok) {
            good.insert(candidate);
        }
    }

    // for (auto x : ans) {
    //  cout << x << " ";
    // }
    cout << good.size() << endl;

    return 0;
}