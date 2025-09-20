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
 
vii moves = {{0,1},{0,-1},{1,0},{-1,0}};
char grid[10000][10000];
int n,m = 0;
int ans = 0;
int reached = 0;


//Verificar movimientos
inline bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 'Q');
}

//DFS en grid
void dfs(int x, int y) {
    grid[x][y] = '.';
    
    for (auto move : moves) {
        int nextX = x+move.first;
        int nextY = y+move.second;
        
        if (valid(nextX,nextY)) {
            reached++;
            dfs(nextX,nextY);
        }

    }
}

int main() { _
    cin >> n >> m;
    char a;
    int qs = 0;

    for (int i =0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            grid[i][j] = a;
            if (a == 'Q') {
                qs++;
            }
        }
    }

    int ans = INT_MAX;
    ii hPos;
    for (int i =0 ; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int curr = 0;
            if (grid[i][j] == 'Q') {
                for (auto move : moves) {
                    int nextX = i+move.first;
                    int nextY = j+move.second;

                    if (valid(nextX,nextY)) {
                        curr++;
                    }

                }

                if (curr > 0 && curr < ans) {
                    ans = curr;
                }
            } else if (grid[i][j] == 'H') {
                hPos = {i,j};
            }
        }
    }

    if (ans == INT_MAX) {
        ans = -1;
    }

    dfs(hPos.first, hPos.second);

    if (reached != qs) {
        ans = 0;
    }

    cout << ans << endl;
    return 0;
}