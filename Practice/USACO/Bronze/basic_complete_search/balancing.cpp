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
 
int check(int a, int b, vii & pairs) {
    int tr = 0;
    int tl = 0;
    int br = 0;
    int bl = 0;
    for (auto x : pairs) {
        if (x.first > a && x.second > b) {
            tr++;
        } else if (x.first > a && x.second < b) {
            br++;
        } else if (x.first < a && x.second > b) {
            tl++;
        } else {
            bl++;
        }
    }
    return max(max(tr,br), max(tl,bl));
}

int main() { _
    ifstream in("balancing.in");
    ofstream out("balancing.out");

    int n,m,a,b;
    in >> n >> m;

    vii pairs;
    for (int i = 0; i < n; i++) {
        in >> a >> b;
        pairs.pb({a,b});
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = min(ans, check(pairs[i].first+1, pairs[j].second+1, pairs));
        }
    }


    out << ans << endl;

    return 0;
}