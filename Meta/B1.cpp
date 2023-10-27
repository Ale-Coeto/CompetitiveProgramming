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
vi primes({2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41});

vi nums;
vi sumA;
vector<vi> ans;
//act == num
void vals(int num, int total, vi &options, int sum, vector<vi> &ans) {

    if (num == 1 || sum > 41 || options.size() > 100)
        return;

    if (total == 1 && sum <= 41) {
        ans.push_back(options);
        return;
    }

    for (int i = num; i >= 1; i--) {
        if (total % i == 0)
        {
            options.push_back(i);
            vals(total / i, i, options, sum, ans);
            options.pop_back();
        }
    }
    
    
}

void solve()
{
    int p;
    cin >> p;

    vector<int> values;
    vector<vector<int>> answers;

    // cout << "t";
    // return;
    explore(p, 41, values, 0, answers);
    

    if (answers.size() > 0)
    {
        int minSize = 100;
        int index = 0;
        for (int i = 0; i < answers.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < answers[i].size(); j++)
            {
                sum += answers[i][j];
            }

            for (int j = 41 - sum; j >= 1; j--)
                answers[i].push_back(1);

            if (answers[i].size() < minSize)
            {
                minSize = answers[i].size();
                index = i;
            }
        }

        cout << minSize << " ";
        sort(answers[index].begin(), answers[index].end());
        for (auto x : answers[index])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << "-1\n";
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto start = chrono::high_resolution_clock::now();

    ll t;
    cin >> t;
    
    return 0;
}


int main() { _
    int T, P;
    cin >> T;
    int i = 1;
    for (int it = 1; it <= ; it++)
    {
        cout << "Case #" << it << ": ";
        solve();
    }

    }

    

    return 0;   
}