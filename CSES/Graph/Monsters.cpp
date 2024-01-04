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
vector<char> dir = {'U','D','R','L'};
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
                if (map[nextI][nextJ] != '#') {
                    map[nextI][nextJ] = 'M';
                    monsterQ.push({nextI, nextJ});
                }
            }
        }
    }

}

void bfs(vector<vector<char>> &map, ii start) {

    queue<ii> q;
    q.push(start);

    while (!q.empty()) {

        
        ii front = q.front();
        q.pop();
        updateMonsters(map);

        cout << front.first << " " << front.second << endl;

        if (front.first == 0 || front.second == 0 || front.first == n-1 || front.second == m-1) {
            goal = {front.first,front.second};
            cout << "end";
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
 
int main() { _
    cin >> n >> m;
    cout << n << m << endl; 
    vector<vector<char>> map(n,vector<char>(m,'.'));
    char a;
    ii start;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            map[i][j] = a;
            if (a == 'A')
                start = {i,j};
        }
    }



    bfs(map, start);

    cout << endl;
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j];
        }

        cout << endl;
    }
    cout << endl;

    cout << goal.first << " "<< goal.second;


    return 0;
}