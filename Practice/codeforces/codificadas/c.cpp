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
    int n, p;
    string word;
    cin >> n;
    map<string, int> words;
    map<string, int> total;

    for (int i = 0; i < n; i++) {
        cin >> p;
        unordered_set<string> temp;
        while (p--) {
            cin >> word;
            temp.insert(word);
            total[word]++;
        }
        for (auto word : temp) {
            words[word]++;
        }
    }

    priority_queue<pair<int,string>> pq;
    map<int, vector<string>> mp;


    for (auto word : words) {
        if (word.second == n) {
            int number = total[word.first];
            mp[number].pb(word.first);
            // pq.push({number, word.first});
        }
    }

    vector<vector<string>> ans;

    for (auto x : mp) {
        sort(x.second.begin(), x.second.end());
        reverse(x.second.begin(), x.second.end());
        ans.pb(x.second);
    }

    reverse(ans.begin(), ans.end());

    for (auto x : ans) {
        for (auto w : x) {
            cout << w << endl;
        }
    }

    // while (!pq.empty()) {
    //     cout << pq.top().second << endl;
    //     pq.pop();
    // }


    return 0;
}