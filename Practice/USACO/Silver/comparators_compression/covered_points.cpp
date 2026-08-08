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
 
bool comp(pair<ll,ll> & one, pair<ll,ll> & two) {
    if (one.first == two.first) {
        return one.second < two.second;
    }
    return one.first < two.first;
}

int main() { _
    int n;
    ll a, b;
    cin >> n;

    vector<pair<ll,ll>> vec;
    while (n--) {
        cin >> a >> b;
        vec.pb({a,b});
    }

    sort(vec.begin(), vec.end(), comp);
    ll left = 0;
    map<ll,ll> ans;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i< vec.size(); i++) {
        
        while (!pq.empty() && pq.top() < vec[i].first) {
            ll top = pq.top();
            ans[pq.size()] += (pq.top() - left) + 1;
            pq.pop();
            left = top+1;
            while (!pq.empty() && pq.top() == top){
                pq.pop();
            }
        }
        
        if (!pq.empty() && pq.top() >= vec[i].first) {
            ans[pq.size()] += (vec[i].first-left);
        }

        left = vec[i].first;
        pq.push(vec[i].second);
    }

    while (!pq.empty()) { 
        ll top = pq.top();
        ans[pq.size()] += (pq.top() - left) + 1;
        pq.pop();
        left = top+1;
        while (!pq.empty() && pq.top() == top){
            pq.pop();
        }
    }
    for (int i = 1; i <= vec.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}