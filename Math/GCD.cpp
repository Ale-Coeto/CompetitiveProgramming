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

int gcd(int a, int b) { 
    return b == 0 ? a : gcd(b, a % b); 
}

int lcm(int a, int b) { 
    return a * (b / gcd(a, b)); 
}

// Para encontrar soluciones a ax + by = c
int x, y, d;
void extendedEuclid(int a, int b) {
    if (b == 0) { 
        x = 1; y = 0; d = a; 
        return; 
    }
    extendedEuclid(b, a % b); 
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

int main() { _
    int a = 20, b = 12;
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
return 0;
}