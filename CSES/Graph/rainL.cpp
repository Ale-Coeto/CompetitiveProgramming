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
 
    vector<pair<int,int>> moves = {{0,1},{0,-1},{1,0},{-1,0}};
    int sizeI, sizeJ;
    int maxT = 0;

    inline bool isValid(int i, int j, vector<vector<int>>& grid) {
        return (i >= 0 && i < sizeI && j >= 0 && j < sizeJ && grid[i][j] != 51);
    }

    int bfs(int i, int j, vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({(-1*grid[i][j]), {i,j}});
        grid[i][j] = 51;
        int minT = 0;

        while (!pq.empty()) {
            pair<int,pair<int,int>> front = pq.top();
            pq.pop();
            minT = min(minT,front.first);
            cout << front.first << endl;

            if (front.second.first == sizeI-1 && front.second.second == sizeJ-1) return minT*-1;

            for (auto move : moves) {
                int newI = front.second.first + move.first;
                int newJ = front.second.second + move.second;

                if (isValid(newI,newJ,grid)){
                    pq.push({(-1*grid[newI][newJ]), {newI,newJ}});
                    grid[newI][newJ] = 51;
                }
            }

        }

        return -1*minT;


    }

    int swimInWater(vector<vector<int>>& grid) {
        sizeI = grid.size();
        sizeJ = grid[0].size();
        return bfs(0,0,grid);
        
    }

int main() { _
    vector<vector<int> > a1 = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    int x = swimInWater(a1);
    cout << "ans: " << x;

return 0;
}