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
 
// Binomial coefficients 
// C(n, 0) = C(n, n) = 1 // base cases.
// C(n, k) = C(n − 1, k − 1) + C(n − 1, k) // take or ignore an item, n>k> 0.

// Catalan numbers
// Cat(n + 1) = (2n+2)×(2n+1)  × Cat(n)
//              /(n+2)×(n+1) 
// or m = n + 1


// ii floydCycleFinding(int x0) { // function int f(int x) is defined earlier
//     // 1st part: finding k*mu, hare’s speed is 2x tortoise’s
//     int tortoise = f(x0), hare = f(f(x0)); // f(x0) is the node next to x0
//     while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
//     // 2nd part: finding mu, hare and tortoise move at the same speed
//     int mu = 0; hare = x0;
//     while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++;}
//     // 3rd part: finding lambda, hare moves, tortoise stays
//     int lambda = 1; hare = f(tortoise);
//     while (tortoise != hare) { hare = f(hare); lambda++; }
//     return ii(mu,lambda);
// }

int main() { _
 
return 0;
}