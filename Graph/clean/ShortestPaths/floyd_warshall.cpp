/*
    Algorithm for all source shortest paths
    O(n^3)
*/

#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
#define pb push_back

#define MAXN 400


int INF = INT_MAX;
vector<vi> dp(MAXN, vi(MAXN, INF)); //Update MAX to max size

// For vertices from 1-n
void floydWarshall(int n) {
    // Diagonal
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] == INF || dp[k][j] == INF) continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}
 
int main() {
    
    dp[1][2] = dp[2][1] = 3;
    dp[1][4] = dp[4][1] = 7;
    dp[2][3] = dp[3][2] = 1;
    dp[3][4] = dp[4][3] = 2;
    dp[2][4] = dp[4][2] = 5;
    
    floydWarshall(4);
    
    cout << "\nAfter Floyd-Warshall (shortest paths):" << endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (dp[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dp[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}