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
 
bool canAssign(ll maxDist, const vi& personas, const vii& bodegas) {
    int n = personas.size();
    int k = bodegas.size();
    
    vi capacity(k);
    for (int i = 0; i < k; i++) {
        capacity[i] = bodegas[i].second;
    }
    
    for (int i = 0; i < n; i++) {
        ll personPos = personas[i];
        bool assigned = false;
        
        for (int j = 0; j < k; j++) {
            ll warehousePos = bodegas[j].first;
            ll distance = abs(personPos - warehousePos);
            
            if (distance <= maxDist && capacity[j] > 0) {
                capacity[j]--;
                assigned = true;
                break;
            }
        }
        
        if (!assigned) {
            return false;
        }
    }
    
    return true;
}

int main() { _
    int n,k,a;
    vi personas;

    cin >> n >> k;

    while (n--) {
        cin >> a;
        personas.pb(a);
    }

    vi posB;
    vi capacidad;
    vector<ii> bodegas;
    for (int i = 0; i < k; i++) {
        cin >> a;
        posB.pb(a);
    }

    for (int i = 0; i < k; i++) {
        cin >> a;
        bodegas.pb({posB[i], a});
    }

    sort(personas.begin(), personas.end());
    sort(bodegas.begin(), bodegas.end());

    int low = 0;
    int high = max(abs(personas[0] - bodegas[bodegas.size()-1].first), abs(personas[personas.size()-1] - bodegas[0].first));
    int mid = 0;
    while (low < high) {
        mid = low + (high - low)/2;

        if (canAssign(mid, personas, bodegas)) {
            high = mid;
        } else {
            low = mid + 1;
        }
 
    }

    cout << low << endl;
    return 0;
}