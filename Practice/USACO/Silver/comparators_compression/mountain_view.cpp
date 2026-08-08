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

bool cmp(pair<ll,ll> & first, pair<ll,ll> & second) {
    if (first.first == second.second) {
        return first.second > second.second;
    }
    return first.first < second.first;
}
 
int main() { _
    ifstream in("mountains.in");
    ofstream out("mountains.out");

    int n;
    ll x,y;
    vector<pair<ll,ll>> mts;

    in >> n;
    while (n--) {
        in >> x >> y;
        mts.pb({x-y,x+y});
    }

    sort(mts.begin(), mts.end(), cmp);

    int ref = 0;
    ll ans = mts.size();

    for (int i = 1; i < mts.size(); i++) {
        // cout << mts[i].first << " " << mts[i].second << endl;
        if (mts[i].first >= mts[ref].second || mts[i].second > mts[ref].second) {
            ref = i;
        } else {
            ans--;
        }
    }

    out << ans << endl;
    return 0;
}