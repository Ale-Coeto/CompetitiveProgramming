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
unordered_map<char, int> values;

void solve(string &input) {
    vi dp(input.size(), 0);
    dp[0] = values[input[0]];  
    int ans = 0;

    if (dp[0] == 1)
        ans = 1;

    if (input.length() == 1) {
        cout << ans << endl;
        return;
    }

    if (input[1] == '*')
        dp[1] = -1;
    else
        dp[1] = dp[0] > -1 ? dp[0] + values[input[1]] : values[input[1]];

    ans = max(ans, dp[1]);

    for (int i = 2; i < input.length(); i++) {
        if (input[i] == '*')
            dp[i] = -1;
        else {
            int prev1 = dp[i-2];
            int prev2 = dp[i-1];
            if (prev1 == -1 && prev2 == -1) {
                cout << ans << endl;
                return;
            }

            dp[i] = values[input[i]] + max(prev1, prev2);
            ans = max(ans, dp[i]);
        }


    }

    cout << ans << endl;
}

int main() { _

    values['.'] = 0;
    values['@'] = 1;
    values['*'] = -1;

    int t, n;
    cin >> t;
    string input;

    while (t--) {
        cin >> n;
        cin >> input;
        solve(input);
    }

    return 0;
}