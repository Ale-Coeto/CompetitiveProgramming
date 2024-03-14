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
 
vector<vi> solutions;

void solve(vi & nums) {

    vi dp(nums.size(), 1);
    vi prev(nums.size(), -1);

    ii ans = {1,0};
    
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[j] > nums[i] && dp[i] + 1 > dp[j]) {
                dp[j] = dp[i] + 1;
                prev[j] = i;
                if (dp[j] >= ans.first) {
                    ans = {dp[j], j};
                }
            }
        }
    }

    // cout << "Max hits: " << ans.first << endl;
    int index = ans.second;

    vi ansv;
    while (index != -1) {
        ansv.pb(nums[index]);
        // cout << index << " " << nums[index] <<  endl;
        index = prev[index];
    }

    vi sol;
    for (int i = ansv.size()-1; i >= 0; i--) {
        sol.pb(ansv[i]);
        // cout << ansv[i] << endl;
    }
    solutions.push_back(sol);
    
}

int main() { _
    int t, a;
    string x;
    getline(cin, x);
    t = stoi(x);

    // getline(cin, x);
    
    getline(cin, x);
    
    cout << x;
    while (t--) {
        vi nums;
        while (getline(cin, x) && !x.empty()) {

            nums.pb(stoi(x));

        }
        // cout <<"size"<< nums.size() << endl;
        solve(nums);
        // cout << endl;
        // cout << "end";
    }

    for (int i = 0; i < solutions.size() - 1; i++) {
        cout << "Max hits: " << solutions[i].size() << endl;
        for (auto j : solutions[i]) {
            cout << j << endl;
        }
        cout << endl;
    }
    int enda = solutions.size()-1;
    cout << "Max hits: " << solutions[enda].size() << endl;
        for (auto j : solutions[enda]) {
            cout << j << endl;
        }

    return 0;
}