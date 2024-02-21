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
 


int main() { _

    int n, a, b, t;
    cin >> n >> a >> b >> t;

    string s;
    cin >> s;

    stack<int> left;
    stack<int> right;

    int begin = s[0] == 'w' ? b+1 : 1;
    if (begin > t) {
        cout << 0;
        return 0;
    }
    left.push(begin);
    ll sum = begin;

    for (int i = 1; i < n; i++) {
        int val = s[i] == 'w' ? b+a+1 : a+1;
        if (sum + val > t)
            break;

        sum += val;
        // cout << sum << endl;
        left.push(val);
    }

    right.push(begin);
    ll sum2 = begin;
    for (int i = n-1; i > 0; i--) {
        int val = s[i] == 'w' ? b+a+1 : a+1;
        if (sum2 + val > t)
            break;

        sum2 += val;
        right.push(val);
    }

    ll total = sum + sum2 - begin;

    // cout << sum << " " << sum2 << endl;
    int ans = max(left.size(), right.size());
    // cout << left.size() << " "<< right.size() << " " << total << endl;

    while (total > t) {
        // cout << total << " ";
        if (right.empty() && left.empty() && ans == 0) {
            cout << -1;
            return 0;
        }
       if (right.empty() || left.top() > right.top()) {
            total -= left.top();
            left.pop();
       } else {
            total -= right.top();
            right.pop();
       }
    }

    ans = max(ans, int(right.size() + left.size() - 1));
    ans = min(n, ans);
    cout << ans;



    return 0;
}