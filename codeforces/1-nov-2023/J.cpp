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
 
ll _sieve_size = 1000; 
bitset<10000010> bs; 
vi primes;
set<ll> primesSet;

void sieve(ll upperbound) { 
    _sieve_size = upperbound + 1; 
    bs.set(); 
    bs[0] = bs[1] = 0; 
    for (ll i = 2; i <= _sieve_size; i++) 
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i); 
            primesSet.insert((int)i);
        } 
}

bool isPrime(ll N) { 
    if (N <= _sieve_size) 
        return bs[N]; 

    if (primesSet.count(N) == 0)
        return false;
    
    // for (int i = 0; i < (int)primes.size(); i++)
    //     if (N % primes[i] == 0) return false;

    return true; 
}

int main() { _

    ll n, x;
    cin >> n;

    sieve(1000);

    while (n--) {
        cin >> x;
        ll square = sqrtl(x);

        if (square*square == x && isPrime(square)) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0;
}