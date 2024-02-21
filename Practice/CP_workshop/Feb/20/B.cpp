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
    int n, l, h;

    cin >> n;
    vector<int> heights;

    while (n--) {
        cin >> l >> h;
        heights.pb(h);
    }

    stack<int> s;
    s.push(heights[0]);
    int ans = 0;

    for (int i = 1; i < heights.size(); i++) {
        if (heights[i] > s.top()) {
            s.push(heights[i]);
        } else {
            while (!s.empty() && heights[i] < s.top()) {
                s.pop();
                ans++;
                // cout << heights[i] << " ";
            }
            
            if (s.empty() || heights[i] != s.top())
                s.push(heights[i]);
            
        }
    }

    ans += s.size();

    cout << ans << endl;

    return 0;
}