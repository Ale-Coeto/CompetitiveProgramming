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
    ll n,a,b;
    cin >> n;

    vector<pair<ll,pair<ll,int>>> vec;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vec.pb({a,{b,i}});
    }

    sort(vec.begin(), vec.end());

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    int newRoom = 1;
    map<int,int> ans;
    for (auto x : vec) {
        if (pq.empty() || x.first <= pq.top().first) {
            ans[x.second.second] = newRoom;
            pq.push({x.second.first, newRoom++});
        } else if (x.first > pq.top().first) {
            ans[x.second.second] = pq.top().second;
            pq.push({x.second.first, pq.top().second});
            pq.pop();
        }
    }

    cout << newRoom-1 << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}