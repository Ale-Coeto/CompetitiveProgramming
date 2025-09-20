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
    int n,a,b;
    vector<pair<int,int>> bds;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        bds.pb({a,b});
    }

    set<pair<int,int>> ps;
    for (int i = 0; i < bds.size(); i++) {
        for (int j = i+1; j < bds.size(); j++) {
            pair<int,int> a = bds[i];
            pair<int,int> b = bds[j];

            pair<int,int> p = {(abs(a.first - b.first)), (abs(a.second - b.second))};
            if (ps.count(p) > 0) {
                cout << "YES" << endl;
                return 0;
            }
            ps.insert(p);
        }
    }

    cout << "NO" << endl;
    return 0;
}