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

char grid[10000][10000];
vii moves = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
string ans = "Double Petal Flower";

inline bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '.');
}
 
void solve(int i, int j) {

    queue<pair<int,int>> q;
    q.push({i,j});

    while (!q.empty()) {
        pair<int,int> top = q.front();
        grid[top.first][top.second] = '.';
        q.pop();

        for (auto move : moves) {
            int nextX = top.first+move.first;
            int nextY = top.second+move.second;
            int curr = 0;

            if (valid(nextX,nextY)) {
                q.push({nextX, nextY});   
                

            }



        }
        
        if (q.size() > 1) {
            ans = "Triple Corolla Flower";
            return;
        }

        
    }
    
    
}

int main() { _
    char x;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            grid[i][j] = x;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                solve(i, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}