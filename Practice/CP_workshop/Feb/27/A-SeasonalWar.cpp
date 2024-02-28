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
 
vii moves = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};

inline bool isValid(int i , int j , int n) {
    return (i >= 0 && j >= 0 && i < n && j < n);
}
void dfs(vector<string> &grid, int i , int j, int n) {
    grid[i][j] = '0';

    for (auto move : moves) {
        int nextI = i + move.first;
        int nextJ = j + move.second;

        if (isValid(nextI, nextJ, n) && grid[nextI][nextJ] == '1') {
            dfs(grid, nextI, nextJ, n);
        }
    }
}

void solve(int n, int num) {
    vector<string> grid;
    string input;

    for (int i = 0; i < n; i++) {
        cin >> input;
        grid.pb(input);
    }   

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j, n);
                ans++;
            }

        }
    }

    cout << "Image number " << num << " contains " << ans << " war eagles." << endl;

}

int main() { _

    int n;
    int num = 1;
    while (cin >> n) {
        solve(n, num++);
    }

    return 0;
}