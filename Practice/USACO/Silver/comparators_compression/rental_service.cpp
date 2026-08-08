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

ll check(int cap, vii & gals) {
    ll ans = 0;
    for (int i = gals.size()-1; i >= 0; i--) {
        if (cap >= gals[i].second) {
            ans += gals[i].second * gals[i].first;
            cap -= gals[i].second;
        } else {
            ans += cap * gals[i].first;
            break;
        }
    }
    return ans;
}

void reduce(int cap, vii & gals) {
    while (!gals.empty() && cap > 0) {
        if (cap >= gals[gals.size()-1].second) {
            cap -= gals[gals.size()-1].second;
            gals.pop_back();
        } else {
            break;
        }
    }

    if (cap > 0 && !gals.empty()) {
        gals[gals.size()-1].second-= cap;
    }
}
 
int main() { _
    ifstream in("rental.in");
    ofstream out("rental.out");

    int n,m,r,a,b;
    in >> n >> m >> r;

    vi cows;
    while (n--) {
        in >> a;
        cows.pb(a);
    }
    sort(cows.begin(), cows.end()); 

    vii gals;
    while (m--) {
        in >> a >> b;
        gals.pb({b,a});
    }
    sort(gals.begin(), gals.end());

    vi rent;
    while (r--) {
        in >> a;
        rent.pb(a);
    }
    sort(rent.begin(), rent.end());

    int left = 0;
    int right = cows.size()-1;
    ll ans = 0;

    while (left <= right) {
        ll lop = rent.size() > 0 ? rent[rent.size()-1] : 0;
        ll rop = check(cows[right], gals);
        cout << lop << " " << rop << endl;

        if (lop > rop) {
            ans += lop;
            rent.pop_back();
            left++;
        } else {
            ans += rop;
            reduce(cows[right],gals);
            right--;
        }
    }

    out << ans << endl;
    return 0;
}