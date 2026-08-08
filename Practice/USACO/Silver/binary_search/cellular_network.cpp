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

bool possible(ll & dist, vector<ll> & cities, vector<ll> & towers) {
    ll ic = 0;
    ll it = 0;
    ll covered = 0;

    while (ic < cities.size() && it < towers.size()) {
        ll left = towers[it]-dist;
        ll right = towers[it]+dist;

        if (cities[ic] >= left && cities[ic] <= right) {
            covered++;
            ic++;
        } else {
            it++;
        }
    } 
    
    return covered == cities.size();
}
 
int main() { _
    int n,m,a;
    cin >> n >> m;
    vector<ll> cities;
    vector<ll> towers;
    sort(cities.begin(), cities.end());
    sort(towers.begin(), towers.end());

    while (n--) {
        cin >> a;
        cities.pb(a);
    }

    while (m--) {
        cin >> a;
        towers.pb(a);
    }

    ll left = 0;
    ll right = LLONG_MAX;
    ll mid ;

    while (left <= right) {
        mid = left + (right-left)/2;

        if (possible(mid, cities, towers)) {
            right = mid-1;
        } else {
            left = mid+1;
        }
    }

    cout << left << endl;

    return 0;
}