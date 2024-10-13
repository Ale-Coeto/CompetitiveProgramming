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
typedef pair<ll, double> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

int main() { _
    int n,l,a,b,c;
    cin >> n >> l;
    vi stops;
    unordered_map<int,vii> mp;

    while (n--) {
        cin >> a >> b >> c;
        stops.pb(a);
        mp[a].pb({b,c});
    }

    sort(stops.begin(), stops.end());

    // for (auto i : stops) {
    //     cout << i << endl;
    // }

    // auto it = lower_bound(stops.begin(), stops.end(), 9);
    //     int index = it-stops.begin();

    //     cout << index << " " <<  stops[index];
    
    // return 0;
    vector<vi> overlap;
    overlap[0].p
    for (int i = 1; i < stops.size(); i++) {

    }

    double ans = double(l);

    queue<ii> q;
    q.push({0,0});
    while(!q.empty()) {
        ii front = q.front();
        q.pop();
        // cout << front.first << " " << front.second <<  endl;

        auto it = lower_bound(stops.begin(), stops.end(), front.first);
        int index = it-stops.begin();
        bool flag = false;
        ll max_ = LLONG_MAX;
        // cout << index;
        for (int i = index; i < stops.size(); i++) {
            for (auto elem : mp[stops[i]]) {
                if (stops[i] + (elem.first*elem.second) >= l) {
                   double time = (front.second + (stops[i] - front.first));
                //    time += ((l-stops[i])*elem.second)/(elem.first*elem.second);
                   time += double((l-stops[i]))/(elem.first);
                   ans = min(ans, time); 
                } else if (stops[i] > max_ || front.second + (stops[i] - front.first) + elem.second >= ans) {
                    continue;
                } else {
                    q.push({stops[i] + (elem.first*elem.second), front.second + (stops[i] - front.first) + elem.second});
                    flag = true;
                    max_ = max(max_, stops[i] + ll(elem.first*elem.second));
                }
                // cout << front.first << endl;
            }
        }

        if (!flag) {
            ans = min(ans, front.second + (l-front.first));
        }
    }

    cout << ans << endl;
    return 0;
}