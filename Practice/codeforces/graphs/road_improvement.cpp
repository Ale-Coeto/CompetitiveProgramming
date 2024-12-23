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
    int n,a,b;
    cin >> n;
    vector<vi> graph(n+1);
    map<ii,int> indexes;

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        indexes[{min(a,b), max(a,b)}] = i+1;
    }

    queue<ii> q;
    vi visited(n+1, 0);
    q.push({1,0});
    visited[1] = 1;
    map<int,vi> ans;


    while (!q.empty()) {
        ii front = q.front();
        q.pop();

        int counter = 1;
        for (auto x : graph[front.first]) {
            if (!visited[x]) {
                visited[x] = 1;
                if (counter == front.second)
                    counter++;
                
                int roadIndex = indexes[{min(front.first,x), max(front.first,x)}];
                // cout << front.first << " " << x << " " << front.second << " " << counter << " " << roadIndex << endl;
                ans[counter].pb(roadIndex);
                q.push({x,counter});
                counter++;
            }
        }

    }

    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x.second.size() << " ";
        for (auto road : x.second) {
            cout << road << " ";
        }
        cout << endl;
    }
    

    return 0;
}