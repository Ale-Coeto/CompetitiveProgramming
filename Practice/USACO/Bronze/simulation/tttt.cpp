#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstddef>
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
#include <unordered_set>
#include <unordered_map>
 
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
 
int main() { _
    ifstream in("tttt.in");
    ofstream out("tttt.out");

    char a;
    vector<vector<char>> mat(3,vector<char>(3));
    set<char> ind;
    set<pair<char,char>> team;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            in >> a;
            mat[i][j] = a;
        }
    }   

    for (int i = 0; i < 3; i++) {
        if (mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]) {
            ind.insert(mat[i][0]);
        } else if (mat[i][0] == mat[i][1]) {
            team.insert({min(mat[i][0], mat[i][2]), max(mat[i][0], mat[i][2])});
        } else if (mat[i][0] == mat[i][2]) {
           team.insert({min(mat[i][0], mat[i][1]), max(mat[i][0], mat[i][1])}); 
        } else if (mat[i][1] == mat[i][2]) {
            team.insert({min(mat[i][0], mat[i][2]), max(mat[i][0], mat[i][2])});
        }
    }

    for (int i = 0; i < 3; i++) {
        if (mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]) {
            ind.insert(mat[0][i]);
        }  else if (mat[0][i] == mat[1][i]) {
            team.insert({min(mat[0][i], mat[2][i]), max(mat[0][i], mat[2][i])});
        } else if (mat[0][i] == mat[2][i]) {
           team.insert({min(mat[0][i], mat[1][i]), max(mat[0][i], mat[1][i])}); 
        } else if (mat[1][i] == mat[2][i]) {
            team.insert({min(mat[0][i], mat[2][i]), max(mat[0][i], mat[2][i])});
        }
    }

    if (mat[0][0] == mat[1][1] && mat[2][2] == mat[1][1]) {
        ind.insert(mat[0][0]);
    } else if (mat[0][0] == mat[1][1]) {
        team.insert({min(mat[0][0], mat[2][2]), max(mat[0][0], mat[2][2])}); 
    } else if (mat[2][2] == mat[1][1]) {
        team.insert({min(mat[0][0], mat[2][2]), max(mat[0][0], mat[2][2])});
    } else if (mat[0][0] == mat[2][2]) {
        team.insert({min(mat[0][0], mat[1][1]), max(mat[0][0], mat[1][1])});
    }

    if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0]) {
        ind.insert(mat[2][0]);
    } else if (mat[0][2] == mat[1][1]) {
        team.insert({min(mat[0][2], mat[2][0]), max(mat[0][2], mat[2][0])});
    } else if (mat[1][1] == mat[2][0]) {
        team.insert({min(mat[0][2], mat[2][0]), max(mat[0][2], mat[2][0])});
    } else if (mat[0][2] == mat[2][0]) {
        team.insert({min(mat[1][1], mat[2][0]), max(mat[1][1], mat[2][0])});
    }

    out << ind.size() << endl << team.size() << endl;

    return 0;
}