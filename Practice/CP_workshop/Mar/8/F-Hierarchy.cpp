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
int f[1100];

int main() { _
    int n,m;
    int temp,u,v,w;

    while(cin >> n) {
        for(int i = 1; i <= n; i++) {
            cin >> temp;
            f[i] = INF;
        }

        cin >> m;

        for(int i = 1; i <= m; i++) {
            cin >> u >> v >> w;
            if(f[v] > w)
                f[v] = w;
        }

        int flag = 1, k = 1;
        int ans = 0;

        for(int i = 1; i <= n; i++) {
            if (f[i] == INF && k) {
                ans-=INF;
                k=0;
            } else if(f[i] == INF) {
                flag=0;
                break;
            }
            ans += f[i];
        }

        if(flag)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }

    return 0;
    
}