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

vii moves = {{0,1},{0,-1},{1,0},{-1,0}};
int w, h; 

inline bool isValid(ii move) {
    return (move.first >= 0 && move.second >= 0 && move.first < h && move.second < w);
}

void solve(int w, int h) {
    
    char grid[h][w];
    ii start;
    ii end;

    string a;

    for (int i = 0; i < h; i++) {
        cin >> a;
        for (int j = 0; j < w; j++) {
            grid[i][j] = a[j];
            if (a[j] == 'S')
                start = make_pair(i,j);
            if (a[j] == 'D')
                end = make_pair(i,j);
        }

    }

    priority_queue< pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
    vector<vi> dist(h, vi(w, INF));
    vector<vector<bool>> visited(h, vector<bool>(w, false));

    pq.push({0,{start.first, start.second}});
    dist[start.first][start.second] = 0;

    while (!pq.empty()) {
        pair<int, ii> front = pq.top();
        pq.pop();

        if (visited[front.second.first][front.second.second]) continue;
        visited[front.second.first][front.second.second] = true;

        for (ii move : moves) {
            ii nextMove = {front.second.first + move.first, front.second.second + move.second};
            if (isValid(nextMove) && grid[nextMove.first][nextMove.second] != 'X' && grid[nextMove.first][nextMove.second] != 'S') {
                int nextDist = grid[nextMove.first][nextMove.second] - '0';

                if (dist[front.second.first][front.second.second] + nextDist < dist[nextMove.first][nextMove.second]) {
                    dist[nextMove.first][nextMove.second] = dist[front.second.first][front.second.second] + nextDist;
                    pq.push({dist[nextMove.first][nextMove.second], {nextMove.first, nextMove.second}});
                }
            }
        }


    }

    int ans = INF;

    for (auto move : moves) {
        ii nextMove = {end.first + move.first, end.second + move.second};
            if (isValid(nextMove) && grid[nextMove.first][nextMove.second] != 'X') {
                ans = min(ans, dist[nextMove.first][nextMove.second]);
            }
    }

    cout << ans << endl;
}

int main() { _

    while (cin >> w >> h) {
        if (w == 0 || h == 0) continue;
        solve(w,h);
    }
    

    return 0;
}

