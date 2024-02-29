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
 
void solve(unordered_set<int> &vals, unordered_set<int> &del, int sum) {
    int res = sum % 3;
    int miss = 3 - sum % 3;
    // res = (3-res);
    // res %= 3;
    // cout << res << " " ;
    if (res == 0) {
        cout << 0;
    } else if ((miss == 1 && vals.count(1)) || del.count(res) || miss == 1) {
        cout << 1;
    } else {
        cout << 2;
    }
    cout << endl;
}



int main() { _

    int t, n, a;

    cin >> t;
    unordered_set<int> vals;
    unordered_set<int> del;
    int sum = 0;

    while (t--) {   
        sum = 0;
        vals.clear();
        del.clear();
        cin >> n;
        while (n--) {
            cin >> a;
            vals.insert(3 - a%3);
            del.insert(a%3);
            sum += a;
        }

        solve(vals, del, sum);
    }
    return 0;
}