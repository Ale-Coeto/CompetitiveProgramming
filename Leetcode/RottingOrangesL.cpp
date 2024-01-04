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

    vector<pair<int,int>> moves = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int sizeI,sizeJ;
    int oranges = 0;
    int rotten = 0;

    bool isValid(int i, int j, vector<vector<int>>& grid) {
        if (i >= 0 && i < sizeI && j >=0 && j < sizeJ)
            if (grid[i][j] == -1)
                return true;
        return false;
    }

    int bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q) {
        
        int t = 1;

        while (!q.empty())  {
            pair<int,int> front = q.front();
            q.pop();

            cout << "pair:  " << front.first << " " << front.second << " -> " << grid[front.first][front.second] << endl;

            
            for (auto move : moves) {
                int nextI = front.first + move.first;
                int nextJ = front.second + move.second;

                if (isValid(nextI, nextJ, grid)) {
                        rotten++;
                        grid[nextI][nextJ] = grid[front.first][front.second] + 1;
                        t = max(t,grid[nextI][nextJ]);
                        q.push(make_pair(nextI,nextJ));

                }

            }

        }

        return t;
        
    }   

    int orangesRotting(vector<vector<int>>& grid) {
        sizeI = grid.size();
        sizeJ = grid[0].size();
        int total = 0;

        queue<pair<int,int>> q;

        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                if (grid[i][j] == 1) {
                    oranges++;
                    grid[i][j] = -1;
                }
                else if (grid[i][j] == 2) {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
                    
            }
        }

        for (int i = 0; i < sizeI; i++) {
            for (int j = 0; j < sizeJ; j++) {
                if (grid[i][j] == -1)
                    total = bfs(grid,q);
            }
        }

        return (oranges == rotten) ? total : 0;

    }

int main() { _
    vector<vector<int> > a1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << orangesRotting(a1);

return 0;
}