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


    unordered_map<int, int> dp;

    int minCost(vector<int>& cost, int index) {
        if (index == cost.size()-1 || index == cost.size()-2) return cost[index];


        if (dp[index]) return dp[index];
        dp[index] = min(cost[index] + minCost(cost, index + 1), cost[index] + minCost(cost,index+2));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() == 2) return min(cost[0],cost[1]);

       return min(minCost(cost,0),minCost(cost,1));
    }

 
int main() { _
    vector<int> v = {10,15,20};
    cout << minCostClimbingStairs(v) << endl;
return 0;
}