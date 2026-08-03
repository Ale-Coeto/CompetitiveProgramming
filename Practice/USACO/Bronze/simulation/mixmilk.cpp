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
    ifstream in("mixmilk.in");
    ofstream out("mixmilk.out");

    int c1,m1,c2,m2,c3,m3;

    in >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    for (int i = 0; i < 100; i++) {
        int index = i % 3;
        if (index == 0) {
            int cap = m1 + m2;
            if (cap > c2) {
                m2 = c2;
                m1 = cap - c2;
            } else {
                m1 = 0;
                m2 = cap;
            }
        } else if (index == 1) {
           int cap = m2 + m3;
            if (cap > c3) {
                m3 = c3;
                m2 = cap - c3;
            } else {
                m2 = 0;
                m3 = cap;
            } 
        } else {
            int cap = m3 + m1;
            if (cap > c1) {
                m1 = c1;
                m3 = cap - c1;
            } else {
                m3 = 0;
                m1 = cap;
            }
        }
        // cout << m1 << endl << m2 << endl << m3 << endl;
    }

    out << m1 << endl << m2 << endl << m3 << endl;

    return 0;
}