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
typedef vector<int> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

void solve(int &r, int &c) {
    bool row = r > c;
    long long num = max(r, c);

    if (num % 2 == 0) {
        long long starting;
        if (row) {
            starting = num*num;
            cout << starting - c + 1 << endl;
        } else {
            starting = ((num-1) * (num-1)) + 1;
            cout << starting + r - 1 << endl;
        }
    } else {
        long long starting;
        if (row) {
            starting = ((num-1) * (num-1)) + 1;
            cout << starting + c - 1 << endl;
        } else {
            starting = num*num;
            cout << starting - r + 1 << endl;
        }
    }
}

int main() { _
    int t, r, c;
    cin >> t;

    while (t--) {
        cin >> r >> c;
        solve(r, c);
    }
    return 0;
}