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
typedef pair<int, int> p32;
typedef vector<p32> vp32;

#define MAXN 10
#define MOD 1000000007

void print(vi & vec, int n) {
    if (vec.size() == 1)
        cout << "YES" << endl;
    
    else if (vec.size() == 2 && (n & 1) && abs(vec[0] - vec[1]) == 1)
        cout << "YES" << endl;
    
    else if (vec.size() > 2 || vec[0] != vec[1])
        cout << "NO" << endl;
    
    else
        cout << "YES" << endl;
}

void isValid() {
    int n;
    cin >> n;
    vector<ii> a(n);

    unordered_map<int, int> map;
    int x;
    while (n--) {
        cin >> x;
        map[x]++;
    }

    int counter = 0;
    vi vec;

    for (auto x : map) {
        vec.push_back(x.second);
    }
    
    print(vec, n);
    
}

int main() { _

    ll t;
    cin >> t;

    while (t--)
        isValid();
    
    return 0;
}