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
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 

bool solve(int n, ll sum, vi &containers) {
    int ans = sum/n;
    ll curr = 0;

    for (int i = 0; i < containers.size(); i++) {
        int diff = containers[i] - ans;
        curr += diff;
        if (curr < 0) {
            return false;
        }
    }

    return true;

    //4,5,2,1,3
    //1,2
    //3

}

int main() { _

    int t, n, a;
    ll sum;

    cin >> t;


    while (t--) {
        cin >> n;
        vi containers;
        sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a;
            sum += a;
            containers.pb(a);
        }

        cout << (solve(n, sum, containers) ? "YES" : "NO") << endl;

    }


    return 0;
}