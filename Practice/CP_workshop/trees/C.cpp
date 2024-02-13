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
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

unordered_map<int,bool> memo;
int ans = 0;

void traverse(int sum, bool containsD, int &n, int &k, int &d) {
    // cout << " <" << sum << "> ";
    // if (memo[sum] == true) {
    //     // cout << "memo";
    //     return memo[sum];
    //     // return memo[sum];
    // }

    // if (sum == n && containsD) {
    //     cout << "check";
    //     ans++;
    //     return;
    //     // return true;
    // }
    if (sum == n && containsD) {
        // cout << "yes";
        ans++;
        return;
        // return true;
    }

    if (sum > n) {
        // cout << sum << "-nop ";
        return;
        // return false;
    }

    for (int i = 1; i <= k; i++) {
        // if (sum+i == n && (containsD || i == d)) {
        //     cout << sum+i <<  " found ";
        //     ans++;
        //     continue;
        // }
        // else {
            // cout << i << " ";
            // memo[sum+i] = traverse(sum+i, (containsD || i >= d), n,k,d);
            traverse(sum+i, (containsD || i >= d), n,k,d);
        // }
        // if (!memo[sum+i]) break;
    }

    // return false;

}
 
int main() { _

    int n,k,d;

    cin >> n >> k >> d;

    traverse(0, false, n, k, d);

    cout << ans;

    return 0;
}