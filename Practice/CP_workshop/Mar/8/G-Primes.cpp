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
vector<string> primesC;

void sieve(ll upperbound) { 
    _sieve_size = upperbound + 1; 
    bs.set(); 
    bs[0] = bs[1] = 0; 
    for (ll i = 2; i <= _sieve_size; i++) 
        if (bs[i]) {
            for (ll j = i * i; j <= _sieve_size; j += i)
                bs[j] = 0;
            primes.push_back((int)i); 
            primesC.pb(to_string(primes[primes.size()-1]));
        } 
}
bool flag = false;
vector<string> ans;



void solve(int & n, int & t, int curr, int index, int twice, vi ops) {
    if (flag) return;
    if (curr > n || ops.size() > t) {
        return;
    }
    
    if (curr == n && ops.size() == t) {
        string a = "";
        for (int i = 0; i < ops.size()-1; i++) {
            cout << ops[i] << "+";
        }
        cout << ops[ops.size()-1] << endl;
        flag = true;
        return;
    }

    for (int i = index; i < primesC.size(); i++) {
        int num = stoi(primesC[i]);
        // if (num > n) continue;

        if (num % 2 != 0) {
            if (twice == 2) {
                twice = 0;
                continue;
            } else {
                // if (curr+num <= n) {
                //     ops.pb(num);
                //     solve(n,t,curr+num,i,twice++,ops);
                //     ops.pop_back();
                // }
                curr += num;
                ops.pb(num);
                solve(n,t,curr,i,twice++,ops);
                curr -= num;
                ops.pop_back();
            }
        } else {
            curr += num;
            ops.pb(num);
            solve(n,t,curr,i+1,0,ops);
            curr -= num;
            ops.pop_back();
        }
        
    }

    
}

int main() { _
    int n, t;
    sieve(299);
    sort(primesC.begin(), primesC.end());

    vi temp;

    // vi dp[1001];
    // for (int i = 1; i < 1001; i++) {
    //     solve(n,t,0,0,0,temp);
    // }
    
    int count = 1;
    while (cin >> n >> t) {
        if (n == 0 || t == 0) break;

        cout << "CASE " << count++ << ": \n";
        solve(n,t,0,0,0,temp);
        // solve(n,t);


        if (!flag) 
            cout << "No solution." << endl;

        flag = false;
    }

    return 0;
}