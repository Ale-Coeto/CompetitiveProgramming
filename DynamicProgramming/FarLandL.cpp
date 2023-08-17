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
    int dp[105][105];
        int maxD = -1;

    int maxDistance(vector<vector<int>>& grid) {
        if (grid.size() < 2) return -1;
        dp[0][0] = (grid[0][0] == 1) ? 0 : 1;   

        for (int n = 2; n <= grid.size(); n++) {
            for (int i = 0; i < n; i++) {

                if (grid[i][n-1] == 1) dp[i][n-1] = 0;
                else {
                    if (i-1 < 0)
                        dp[i][n-1] = 1 + dp[i][n-2];
                    else
                        dp[i][n-1] = (dp[i-1][n-1] == 0 || dp[i][n-2] == 0) ? 1 : 1 + max(dp[i-1][n-1], dp[i][n-2]);

                    maxD = max(maxD,dp[i][n-1]);
                }

                if (grid[n-1][i] == 1) dp[n-1][i] = 0;
                else {
                    if (i-1 < 0)
                        dp[n-1][i] = 1 + dp[n-2][i];
                    else
                        dp[n-1][i] = (dp[n-1][i-1] == 0 || dp[n-2][i] == 0) ? 1 : 1 + max(dp[n-1][i-1], dp[n-2][i]);

                    maxD = max(maxD,dp[n-1][i]);
                } 
            }
        }

        return maxD;
    }

int main() { _
vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,1}};




cout << "ans: " << maxDistance(grid) << endl;

for(int i = 0; i < grid.size(); i++) {
    for(int j = 0; j < grid[0].size(); j++) {
        cout << dp[i][j] << " ";
    }
    cout << endl;
}
 
return 0;
}