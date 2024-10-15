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
    int n,k,d,a,b;
    cin >> n >> k >> d;
    vector<vi> graph(n+1);
    vi visited(n+1,0);
    set<ii> roads;
    map<ii,int> indexes;
    queue<int> q;

    vi police;

    while (k--) {
        cin >> a;
        q.push(a);
        visited[a] = 1;
    } 

    for (int i = 0; i < n-1; i++) {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
        roads.insert({min(a,b), max(a,b)});
        indexes[{min(a,b), max(a,b)}] = i+1;
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        for (auto x : graph[front]) {
            if (!visited[x]) {
                visited[x] = 1;
                q.push(x);
                roads.erase({min(front,x), max(front,x)});
            }
        }

    }

    cout << roads.size() << endl;
    for (auto x : roads) {
        cout << indexes[x] << " "; 
    }
    


    return 0;
}