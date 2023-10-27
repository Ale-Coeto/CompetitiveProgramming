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
typedef vector<double> vi;
typedef vector<ii> vii;
 
#define MAXN 10
#define MOD 1000000007
 
int main() { _
    int T,N;    
    int i = 1;
    

    cin >> T;
    while(T--) {
        cin >> N;
        int size = N;
        vi pqMax;
        vi pqMin;
        while (N--) {
            
            double x;
            cin >> x;

            if (pqMin.size() < 3) {
                pqMin.pb(x);
                sort(pqMin.begin(), pqMin.end());
            } else {
                if (x < pqMin[2]) {
                    pqMin.pb(x);
                    sort(pqMin.begin(), pqMin.end());
                    pqMin.pop_back();
                }                
            } 

            if (pqMax.size() < 3) {
                pqMax.pb(x);
                sort(pqMax.begin(), pqMax.end(), greater<int>());
            } else {
                if (x > pqMax[2]) {
                    pqMax.pb(x);
                    sort(pqMax.begin(), pqMax.end(), greater<int>());
                    pqMax.pop_back();
                }
            }

        }

        if (size != 5) {
            long double disMax = (pqMax[0]+pqMax[1])/2;
            long double disMin = (pqMin[0]+pqMin[1])/2;
            cout << "Case #"<< i << ": " << disMax-disMin << endl;
        } else {
            long double disMax1 = (pqMax[0]+pqMax[1])/2;
            long double ans1 = disMax1-((pqMin[0]+pqMin[2])/2);

            long double disMax2 = (pqMax[0]+pqMax[2])/2;
            long double ans2 = disMax2-((pqMin[0]+pqMin[1])/2);

            cout << "Case #"<< i << ": " << max(ans1,ans2) << endl;
        }
        i++;


        
    }

    return 0;
}