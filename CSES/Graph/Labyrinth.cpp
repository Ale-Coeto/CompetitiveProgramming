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
 
#define MAXN 1005
#define MOD 1000000007

string grid[MAXN][MAXN];
int path[MAXN][MAXN];


queue<ii> q;
vii moves = {{0,1},{0,-1},{1,0},{-1,0}};
string dir[4] = {"R","L","D","U"};
int n = 0, m = 0;

bool isValid(int x, int y) {
    if (x >= 0 && y >= 0 && x < n && y < m)
        if (grid[x][y] == "")
            return true;
    return false;
}

int bfs2(ii start, ii end) {
    q.push(start);
    int x,y;
    
    grid[start.first][start.second] = "A";
    int count  = 0;

    while (!q.empty()) {
        count++;

        ii f = q.front();
        q.pop();
        x = f.first;
        y = f.second;
        

        for (int i = 0; i < 4; i++) {
            int x2 = x + moves[i].first;
            int y2 = y + moves[i].second;
            //cout << x2 << " " << y2 << endl;
            if (isValid(x2,y2)) {
                 grid[x2][y2] = '0';
                 path[x2][y2] = i;
                 q.push({x2,y2});
                 if (x2 == end.first && y2 == end.second) return count;

            }
               
        }

    }

    return -1;

}

void findPath(ii start, ii end) {
    vi steps;
    while (!(end.first == start.first && end.second == start.second)) {
        int p = path[end.first][end.second];
        steps.pb(p);
        end = {end.first - moves[p].first, end.second - moves[p].second};
    }
    reverse(steps.begin(), steps.end());

    cout << steps.size() << endl;
    for (int i : steps) {
        cout << dir[i];
    }
}

string bfs(ii start, ii end) {
    q.push(start);
    int x,y;
    
    grid[start.first][start.second] = "A";

    while (!q.empty()) {
        ii f = q.front();
        q.pop();
        x = f.first;
        y = f.second;
        string curr = grid[x][y];
        
        if (x == end.first && y == end.second) return grid[x][y];

        for (int i = 0; i < 4; i++) {
            int x2 = x + moves[i].first;
            int y2 = y + moves[i].second;
            string m = dir[i];
            if (isValid(x2,y2)) {
                 q.push({x2,y2});
                 string r = curr + m;
                 grid[x2][y2] = r;
            }
               
        }

    }

    return "NO";

}

int main() { 
    _

    ii start;
    ii end;
    cin >> n >> m;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if (a == '#') grid[i][j] = "1";
            else if (a == '.') grid[i][j] = "";
            else if (a == 'A') {
                start.first = i;
                start.second = j;
                grid[i][j] = "";
            } else {
                end.first = i;
                end.second = j;
                grid[i][j] = "";
            }
        }
    }

        
     int ans = bfs2(start,end);

     if (ans == -1) {
        cout << "NO";
     } else {
        cout << "YES" << endl;
        findPath(start, end);
     }




return 0;
}