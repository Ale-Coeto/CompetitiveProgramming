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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 
int main() { _
    int n,x,a;

    cin >> n >> x;
    ii minN = {INF, 0};
    vi nums;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a < minN.first) {
            minN = {a, i};
        }
        nums.pb(a);
    }

    ll sum = 0;
    if (minN.first >= 2) {

        for (int i = 0; i < nums.size(); i++) {
            nums[i] -= minN.first - 1;
            sum += minN.first - 1;
        }
    }
    
    for (int i = x-1; i >= -1; i--) {
        if (i == -1) i = nums.size()-1;

        if (nums[i] == 0) {
            // cout << sum;
            nums[i] = sum;
            break;
        } else {
            nums[i]--;
            sum++;
        }

    }

    for (auto i : nums) {
        cout << i << " ";
    }


    return 0;
}