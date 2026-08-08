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
 
bool cmp(pair<ll,pair<ll,int>> & f1, pair<ll,pair<ll,int>> & f2) {
    if (f1.first == f2.first) {
        return f1.second.second < f2.second.second;
    }
    return f1.first < f2.first;
}

int main() { _
    ifstream in("convention2.in");
    ofstream out("convention2.out");

    ll n,a,b;
    in >> n;

    vector<pair<ll,pair<ll,int>>> vec;
    for (int i = n; i > 0; i--) {
        in >> a >> b;
        vec.pb({a,{b,i}});
    }

    sort(vec.begin(), vec.end(), cmp); 

    priority_queue<pair<int, pair<ll,ll>>> pq;
    ll time = -1;
    ll ans = 0;
    
    int index = 0;
    int processed = 0;
    bool processing = false;

    while (processed < vec.size()) {
            if (pq.empty() && index < vec.size() && vec[index].first > time) {
                time = vec[index].first + vec[index].second.first;
                index++;
                processed++;
            } else if (index >= vec.size() || (!pq.empty() && index < vec.size() && vec[index].first > time)) {
               ans = max(ans, time-pq.top().second.first);
                time += pq.top().second.second;
                pq.pop(); 
            
            processed++;
        } else {
           pq.push({vec[index].second.second, {vec[index].first, vec[index].second.first}});
            index++; 
        }
    }
    out << ans << endl;

    return 0;
}