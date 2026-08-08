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
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

bool possible(vi & nums, int & size, int & t) {
    int index = nums.size()-size;
    ll time = 1;

    priority_queue<ll, vi, greater<ll>>pq;
    for (int i = 0; i < size; i++) {
        pq.push(nums[i]);
        time = max(time, nums[i]);
    }

    for (int i = size; i < nums.size(); i++) {
        ll top = pq.top();
        time = max(time, nums[i]+top);
        pq.push(nums[i]+top);
        pq.pop();
    }

    // cout << size << " " << time << endl;
    return time <= t;   
}
 
int main() { _
    ifstream in("cowdance.in");
    ofstream out("cowdance.out");
    int n,t,a;

    in >> n >> t;
    int left = 1;
    int right = n;

    vi nums;
    while (n--) {
        in >> a;
        nums.pb(a);
    }
    
    while (left < right) {
        int mid = left + (right-left)/2;

        if (possible(nums, mid, t)) {
            right = mid;
        } else {
            left = mid+1;
        }
    }

    out << left << endl;

    return 0;
}