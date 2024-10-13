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
typedef vector<ll> vll;
 
#define MAXN 10000001
#define MOD 1000000007

void precalcFactorial(vll &factorial, ll m)
{
    factorial[0] = 1;
    for (int i = 1; i <= MAXN; i++)
    {
        factorial[i] = factorial[i - 1] * i % m;
    }
}

long long binomial_coefficient(int n, int k, ll m, vll &factorial)
{
    return (factorial[n] / (factorial[k] * factorial[n - k] % m)) % m;
}

int C(int n, int k)
{
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (int)(res + 0.01);
}

int main() { _
    vll fact(MAXN);
    precalcFactorial(fact,MOD); 
    cout << binomial_coefficient(3,2,MOD,fact) << endl;
    cout << C(2,3);
    

    return 0;
}
