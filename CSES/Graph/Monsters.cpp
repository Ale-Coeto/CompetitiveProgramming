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
vector<char> dir = {'R','L','D','U'};
map<char,ii> rev;

ii moves[] = {{0,1},{0,-1},{1,0},{-1,0}};

int n, m;
ii goal = {-1,-1};
queue<ii> monsterQ;

inline bool isPossible(ii move) {
    return (move.first >= 0 && move.second >= 0 && move.first < n && move.second < m);
}

void updateMonsters(vector<vector<char>> &map) {
    int size = monsterQ.size();
    for (int i = 0; i < size; i++) {
        ii front = monsterQ.front();
        monsterQ.pop();

        for (int i = 0; i < 4; i++) {
            int nextI = front.first + moves[i].first;
            int nextJ = front.second + moves[i].second;

            if (isPossible({nextI,nextJ})) {
                if (map[nextI][nextJ] == '.') {
                    map[nextI][nextJ] = 'M';
                    monsterQ.push({nextI, nextJ});
                }
            }
        }
    }

    //    cout << endl;
    // for (int i = 0; i < map.size(); i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << map[i][j];
    //     }

    //     cout << endl;
    // }
    // cout << endl;

}

void print(vector<vector<char>> &map, ii &start) {
    stack<char> path;

    while (!(goal.first == start.first && goal.second == start.second)) {
        path.push(map[goal.first][goal.second]);
        ii curr = {goal.first,goal.second};
        goal.first += rev[map[curr.first][curr.second]].first;
        goal.second += rev[map[curr.first][curr.second]].second;
    }

    cout << "YES" << endl << path.size() << endl;

    while (!path.empty()) {
        cout << path.top();
        path.pop();
    }
}

void bfs(vector<vector<char>> &map, ii start) {

    queue<ii> q;
    q.push(start);

    while (!q.empty()) {

        int size = q.size();
        updateMonsters(map);

        for (int i = 0; i < size; i++) {
            
            ii front = q.front();
            q.pop();
            
            if (front.first == 0 || front.second == 0 || front.first == n-1 || front.second == m-1) {
                goal = {front.first,front.second};
                break;
            }

            for (int i = 0; i < 4; i++) {
                int nextI = front.first + moves[i].first;
                int nextJ = front.second + moves[i].second;

                if (isPossible({nextI,nextJ})) {
                    if (map[nextI][nextJ] == '.') {
                        map[nextI][nextJ] = dir[i];
                        q.push({nextI, nextJ});
                    }
                }
            }

        }
    }
}
 
int main() { _
    cin >> n >> m;
    vector<vector<char>> map(n,vector<char>(m,'.'));
    char a;
    ii start;
    rev['R'] = {0,-1};
    rev['L'] = {0,1};
    rev['U'] = {1,0};
    rev['D'] = {-1,0};


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            map[i][j] = a;
            if (a == 'A')
                start = {i,j};
            if (a == 'M')
                monsterQ.push({i,j});
        }
    }



    bfs(map, start);

    
    if (goal.first != -1) {
        print(map,start);
    } else {
        cout << "NO";
    }

 



    return 0;
}