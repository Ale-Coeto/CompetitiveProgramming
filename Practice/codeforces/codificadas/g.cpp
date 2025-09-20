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
typedef vector<char> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

vector<vi> generate(vector<vi> & init, vector<vi> ans) {
    vector<vi> newG(init.size()*ans.size(), vi(init[0].size()*ans.size()));

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {

            int begI = i*init.size();
            int begJ = j*init.size();
            int defJ = begJ;

            for (int x = 0; x < init.size(); x++) {
                for (int y = 0; y < init.size(); y++) {
                    if (ans[i][j] == '.') {
                        newG[begI][begJ] = '.';
                    } else {
                        newG[begI][begJ] = init[x][y];
                    }
                    begJ++;
                }
                begI++;
                begJ = defJ;
            }
        }
    }
    return newG;
}
 
int main() { _

    int n,k;
    char val;
    cin >> n >> k;
    vector<vi> init(n, vi(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            init[i][j] = val;
        }
    }

    vector<vi> ans = init;
    
    k--;

    while (k--) {
        ans = generate(init, ans);
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}