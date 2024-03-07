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
 
int main() { _  

    int n, a;

    cin >> n;
    vi nums;

    while (n--) {
        cin >> a;
        nums.pb(a);
    }

    for (int i = 0; i < nums.size(); i++) {
        ii maxN = {nums[0],0};

        for (int j = 1; j < nums.size() - i; j++) {
            if (nums[j] - nums[j-1] >= 2 || nums[j-1] - nums[j] >= 2) {
                cout << "NO";
                return 0;
            }

            if (nums[j] > maxN.first) {
                maxN.first = nums[j];
                maxN.second = j;
            }
        }

        nums.erase(nums.begin() + maxN.second);
        nums.pb(maxN.first);
    }

    cout << "YES";

    //vec.erase(vec.begin() + index);

    return 0;
}