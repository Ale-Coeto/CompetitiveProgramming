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

ll solve(vi & vec, int & target) {
    vi prefix(vec.size());
    prefix[0] = vec[0];

    for (int i = 1; i < vec.size(); i++) {
        prefix[i] = prefix[i-1] + vec[i];
    }
    
    int left = -1;
    ll ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        int remove = left == -1 ? 0 : prefix[left];
        int curr = prefix[i] - remove;

        while (curr > target) {
            curr = prefix[i] - prefix[++left];
        }

        if (curr == target) ans++;
    }

    return ans;

}
 
int main() { _

    int n,x,a;
    cin >> n >> x;
    vi vec;

    while (n--) {
        cin >> a;
        vec.pb(a);
    }

    cout << solve(vec, x) << endl;

    return 0;
}