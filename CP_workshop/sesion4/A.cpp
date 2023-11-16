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


int grid[10000][10000];
vii moves = {{0,1},{0,-1},{1,0},{-1,0}};
int n,m = 0;
int ans = 0;
int size = 0;

inline bool valid(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != 1);
}


void dfs(int x, int y) {
    grid[x][y] = 1;
    

    for (auto move : moves) {
        int nextX = x+move.first;
        int nextY = y+move.second;

        if (valid(nextX,nextY))
            dfs(nextX,nextY);
    }
}

int main() { _

    string s1, s2;
    cin >> s1;
    cin >> s2;
    n = 2;
    m = 2;

    int total = 0;
    for (int i = 0; i < 2; i++) {
        grid[0][i] = (s1[i] == '#') ? 1 : -1;
        total += (s1[i] == '#') ? 1 : 0;
    }

    for (int i = 0; i < 2; i++) {
        grid[1][i] = (s2[i] == '#') ? 1 : -1;
        total += (s2[i] == '#') ? 1 : 0;
    }

    if (total == 4) {
        cout << "Yes";
        return 0;
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == -1) {
                dfs(i,j);
                count++;
            }
        }
    }

    cout << ((count == 1) ? "Yes" : "No");
    
    return 0;
    



    // return 0;
}