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

vii moves = {{0,1},{1,0},{-1,0}};

void solve(vector<set<int>> &rocks, int &n, int &m) {

    vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<int, ii>> q;
    q.push({0,{0,0}});
    int count = 0;

    while (!q.empty()) {
        pair<int, ii> front = q.front();
        q.pop();
        visited[front.second.first][front.second.second]++;

        // cout << front.first << ": " << front.second.first << " " << front.second.second << endl;

        if (front.second.first == n-1 && front.second.second == m-1) {
            cout << front.first << endl;
            return;
        }

        for (auto move : moves) {
            int i = front.second.first + move.first;
            int j = front.second.second + move.second;
            // cout << i << j << endl;
            if (i >= n) i = 0;
            if (i < 0) i = n-1;
            if (j < m && visited[i][j] < n) {

            // cout << "m " << i << " " << j << " " << rocks[j].count((i + front.first) % n) << endl;
                if (!rocks[j].count((i + front.first) % n)) {
                    q.push({front.first + 1, {i, j}});
                    // cout << "p";
                }

            }
        }

    }
        cout << -1 << endl;

}   

int main() { _

    int t, n, m, a;
    cin >> t;

    // vector<vi> grid;
    // map<int, set<int>> rocks;

    while (t--) {
        cin >> n >> m;
        vector<set<int>> rocks(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a;
                if (a == 1)
                    rocks[j].insert(i);
                // grid[i][j] = a;
            }
        }

        // for (auto i : rocks) {
        //     for (auto j : i) { 
        //         cout << j << " ";
        //     }
        //     cout << endl;
        // }


        solve(rocks, n, m);

    }

    return 0;
}