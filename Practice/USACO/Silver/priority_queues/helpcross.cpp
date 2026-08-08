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
#include <iterator>
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

bool search(vi & chicks, ii & cow) {
    if (chicks.empty())
        return false;
    
    auto ans = lower_bound(chicks.begin(), chicks.end(), cow.second);
    // for (auto x : chicks) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << cow.second << " " << *ans << endl;
    if (ans != chicks.end() && *ans <= cow.first) {
        chicks.erase(ans);
        return true;
    }
    return false;
}
 
int main() { _
    ifstream in("helpcross.in");
    ofstream out("helpcross.out");

    int n,m,a,b;
    in >> n >> m;

    vi chicks;
    while (n--) {
        in >> a;
        chicks.pb(a);
    }

    vii cows;
    while (m--) {
        in >> a >> b;
        cows.pb({b,a});
    }

    sort(cows.begin(), cows.end());
    sort(chicks.begin(), chicks.end());

    ll ans = 0;
    for (int i = 0; i < cows.size(); i++) {
        if (search(chicks, cows[i])) {
            ans++;
        }
    }

    out << ans << endl;


    return 0;
}