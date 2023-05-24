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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 
vector<int> graph[MAXN];
vi visited(10000, -1);
int n,m;
queue<int> pq;


void bfs(int u) {
    visited[u] = 0;

    int loops = 0;
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
        loops++;
        
    }
    
//retornar numero de loops para encontrar el tamaño del path a un nodo
}

int main() { _
    // Para recibir nodos y edges
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }

    pq.push(1);
    bfs(1);

    for (int i = 1; i < n+1; i++) {
        cout << visited[i] << " ";
    }

  

    

    return 0;
}