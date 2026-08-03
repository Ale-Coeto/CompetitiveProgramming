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
    ifstream in("speeding.in");
    ofstream out("speeding.out");

    int n,m;
    in >> n >> m;

    queue<pair<int,int>> s;
    int a,b;
    int curr = 0;
    int ans = 0;

    while (n--) {
        in >> a >> b;
        curr += a;
        s.push({curr,b});
    }

    curr = 0;
    while (m--) {
        in >> a >> b;
        curr += a;

        if (curr < s.front().first && b > s.front().second) {
            ans = max(ans, abs(b-s.front().second));
        }

        while (s.size() > 0 && s.front().first <= curr) {
            if (b > s.front().second) {
                ans = max(ans, b-s.front().second);
            }
            s.pop();
        }


        // cout << curr << " " << ans << endl;
    }

    out << ans << endl;

    return 0;
}