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
 
vector<vector<string>> solution;
vector<vector<string>> solveNQueens(int n) {
    string start = string(n,'.');
    vector<string> curr(n, start);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            curr[i][j] = 'Q';
            bt(n,1,curr,i+1,j);
            curr[i][j] = '.';
        }
    }

    return solution;
    
}

void bt(int n, int queens, vector<string> &curr, int ib, int jb) {
    if (queens == n) {
        solution.push_back(curr);
        return;
    }
    
    if (ib >= n) return;

    for (int j = 0; j < n; j++) {
        // if (j != i && )
        curr[ib][j] = 'Q';

        if (possible(curr, ib, j)) {   
            // flag++;                 
            bt(n, queens+1, curr, ib+1, j);
        }
        
        curr[ib][j] = '.';
    }

}

bool possible(vector<string> &curr, int ib, int jb) {
    int count = 0;
    for (int i = 0; i < curr.size(); i++) {
        if (curr[i][jb] == 'Q')
            count++;
    }

    if (count != 1) return false;

    count = -1;
    for (auto i : curr) {
        cout << i << endl;
    }

    int index = jb;
    for (int i = ib; i >= 0; i--) {
        if (jb >= 0 && curr[i][jb] == 'Q') 
            count++;
        jb--;

        if (index < curr.size() && curr[i][index++] == 'Q')
            count++;

    }
    cout << count << endl << endl;
    // cout << count << " ";
    if (count != 1) return false;

    return true;
}   

int main() { _


    return 0;
}