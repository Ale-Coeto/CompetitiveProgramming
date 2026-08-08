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
    ifstream in("measurement.in");
    ofstream out("measurement.out");

    int n,g,a,b,c;
    in >> n >> g;
    vector<pair<int,ii>> vec;
    map<int,int> mp;

    for (int i = 0; i < n; i++) {
        in >> a >> b >> c;
        vec.pb({a,{b,c}});
        mp[b] = g;
    }
    
    sort(vec.begin(), vec.end());
    
    priority_queue<int> pq;
    pq.push(g);
    map<int,int> cows;
    cows[g] = n+1;

    map<int,int> rm;
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        while (cows[pq.top()] <= 0) {
            pq.pop();
        }
        ii prevTop = {pq.top(), cows[pq.top()]};
        cows[mp[vec[i].second.first]]--;
        mp[vec[i].second.first] += vec[i].second.second;
        cows[mp[vec[i].second.first]]++;
        pq.push(mp[vec[i].second.first]);

        while (cows[pq.top()] <= 0) {
            pq.pop();
        }

        ii newTop = {pq.top(), cows[pq.top()]};
        if (prevTop != newTop) {
            ans++;
        }
    }

    out << ans << endl;

    return 0;
}