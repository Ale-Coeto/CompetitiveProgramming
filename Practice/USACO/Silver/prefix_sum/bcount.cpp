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
 
int main() { _
    ifstream in("bcount.in");
    ofstream out("bcount.out");

    int n,q, a, b;
    in >> n >> q;
    vector<vector<int>> psum(n+1, vi(4,0));
    in >> a;
    psum[1][a]++;

    for(int i = 2; i <= n; i++) {
        in >> a;
        psum[i] = psum[i-1];
        psum[i][a]++;
    }

    for (auto x : psum) {
        cout << x[0] << x[1] << x[2] << x[3] << endl;
    }

    while (q--) {
        in >> a >> b;
        a--;
        out << psum[b][1]-psum[a][1] << " " << psum[b][2]-psum[a][2] << " " << psum[b][3]-psum[a][3] << endl;
    }

    return 0;
}