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
typedef vector<vi> vvi;
typedef vector<ll> vll;
 
#define MAXN 10
#define MOD 1000000007
void bfs1(int n, vvi &graph, ll prev, vi &vals, vll &res)
{
    vals[n] += prev;
    res[n] = vals[n];
    for (int &i : graph[n])
    {
        bfs1(i, graph, vals[n], vals, res);
    }
}

void bfs(int u, ) {
    visited[u] = 0;

    while (!pq.empty()) {
        int front = pq.front();
        pq.pop();

        for (int i = 0; i < graph[front].size(); i++) {
            int num = graph[front][i];
            if (visited[num] == -1) {
                pq.push(num);
                visited[num] = visited[front] + 1;
            }
        }
        
    }
    
}

// void bfs(int n, vvi &graph, vi &vals, vll &res)
// {
//     ll prev = 0;
//     queue<int> q;
//     q.push(n);
//     while (!q.empty())
//     {
//         n = q.front();
//         prev += vals[n];
//         res[n] = prev;
//         int v = q.size();
//         for (int i = 0; i < v; i++)
//         {
//             for (auto &i : graph[n])
//             {
//                 q.push(i);
//             }
//         }
//         q.pop();
//     }
// }

int main()
{
    _
    int n, q;
    cin >> n >> q;
    int a, b;
    vvi graph(n + 1);
    vi vals(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].pb(b);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        vals[a] += b;
    }
    vll res(n + 1, 0);
    // bfs(1, )
    bfs1(1, graph, 0, vals, res);
    // bfs(1, graph, vals, res);
    for (int i = 1; i < res.size(); i++)
    {

        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}