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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 1000005
#define MOD 1000000007

vector<vector<pair<ll, ii>>> graph(MAXN);
vector<bool> visited(MAXN, false);
vector<int> type(MAXN);
vi dist(MAXN,LLONG_MAX);

void dijkstra(int n, map<ii, int> & mp) {
    priority_queue< pair<ll,ii>, vector<pair<ll,ii>>, greater<pair<ll,ii>>> pq;
    pq.push({0,{n,0}});
    dist[n] = 0;
    ll ans = 0;

    while (!pq.empty()) {
        pair<ll,ii> front = pq.top();
        pq.pop();

        if (visited[front.second.first]) continue;
        visited[front.second.first] = true;

        for (auto i : graph[front.second.first]) {
            if (dist[front.second.first] + i.second.first <= dist[i.first]) {
                int t = i.second.second;
                
                    // cout << i.first << " " << front.second.first << " " << dist[front.second.first] + i.second.first << " " << t << endl;
                if ((dist[front.second.first] + i.second.first == dist[i.first] && t == 0) || (dist[front.second.first] + i.second.first < dist[i.first])) {
                    type[i.first] = t;
                }
                
                dist[i.first] = dist[front.second.first] + i.second.first;
                pq.push({dist[i.first], {i.first,t}});
            }
        }

    }


}
 
int main() { _
    int n,m,k,a,b,c;
    cin >> n >> m >> k;
    map<ii, int> mp;

    while (m--) {
        cin >> a >> b >> c;
        graph[a].pb({b,{c,0}});
        graph[b].pb({a,{c,0}});
    }


    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        graph[1].pb({a,{b,1}});
        graph[a].pb({1,{b,1}});
    }



    dijkstra(1, mp);

    ll trains = 0;
    for (int i = 2; i <= n; i++) {
        // cout << dist[i] << " " ;
        if (type[i] == 1)
            trains++;
    }
    // cout << k << endl;
    cout << k - trains << endl;

    return 0;
}