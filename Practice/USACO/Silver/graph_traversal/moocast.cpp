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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007

bool connected(vector<pair<ii,int>> & vec, int i, int n) {
    ii p1 = vec[i].first;
    ii p2 = vec[n].first;
    double distance = sqrt(
        (double(p1.first-p2.first)*double(p1.first-p2.first)) + 
        (double(p1.second-p2.second)*double(p1.second-p2.second)));
    return distance <= vec[n].second;
}
 
void traverse(vector<pair<ii,int>> & vec, vi & visited, int n, int & curr) {
    visited[n] = 1;
    curr++;

    for (int i = 0; i < vec.size(); i++) {
        if (!visited[i] && connected(vec, i, n)) {
            traverse(vec, visited, i, curr);
        }
    }
}

int main() { _
    ifstream in("moocast.in");
    ofstream out("moocast.out");

    int n,a,b,c;

    in >> n;

    vector<pair<ii,int>> vec;
    for (int i = 0; i < n; i++) {
        in >> a >> b >> c;
        vec.pb({{a,b},c});
    }

    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        vi visited(n);
        int curr = 0;
        traverse(vec,visited,i, curr);
        ans = max(ans, curr);
    }

    out << ans << endl;

    return 0;
}