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
 
ll _sieve_size; 
bitset<10000010> bs; 
vi primes;

void sieve(ll upperbound) { 
    _sieve_size = upperbound + 1; 
    bs.set(); 
    bs[0] = bs[1] = 0; 
    for (ll i = 2; i <= _sieve_size; i++) 
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i); 
        } 
}

bool isPrime(ll N) { 
    if (N <= _sieve_size) 
        return bs[N]; 

    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;

    return true; 
}

vi primeFactors(ll N) { 
    vi factors;
    ll PF_idx = 0, PF = primes[PF_idx]; 
    while (PF * PF <= N) { 
        while (N % PF == 0) {
            N /= PF; factors.push_back(PF); 
        } 
        PF = primes[++PF_idx];
    }

    if (N != 1) 
        factors.push_back(N); 
    return factors; 
}


int main() { _
    sieve(10000000);
    cout << isPrime(21474836472) << endl;

    vi r = primeFactors(142391208960LL);
    for (vi::iterator i = r.begin(); i != r.end(); i++) 
        cout << *i << " ";
        
 
return 0;
}