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

bool check(vector<vi> & nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i][i] != 0) return false;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i][j] != nums[j][i])
                return false;
        }
    }

    return true;

}

bool flag = true;

bool dfs(vector<vi> & graph, vector<bool> & visited, int n, int parent) {
    visited[n] = true;
    // cout << n << " ";
    for (auto i : graph[n]) {
        if (!visited[i]) {
            if (dfs(graph, visited, i, n))
                return true;
        }

            else if (i != parent) {
                cout << n << " " << i << " " << parent << "par ";
                return true;
            }
        
        
    }

    return false;

}

void solve(vector<vi> & nums) {
    if (!check(nums)) {
        cout << "NO" << endl;
        return;
    }

    vector<vi> graph(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            // if (i == j) {
            //     if ()
            // }
            if (nums[i][j]) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }

        }
    }

    vector<bool> visited(nums.size(), false);
   ;

    if (!dfs(graph,visited,0,-1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


}

int main() { _

    int n, a;

    cin >> n;   
    vector<vi> nums(n,vi(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            nums[i][j] = a;
        }
    }

    solve(nums);
    return 0;
}