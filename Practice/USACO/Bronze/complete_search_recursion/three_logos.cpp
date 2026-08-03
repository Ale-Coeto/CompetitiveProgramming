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
 
bool res = false;
map<int,char> mp;

vector<vector<char>> getNext(vector<int> & perm, vector<ii> & sqs, vector<vector<char>> curr, int index, ii start, bool swapped = false) {
    ii p = sqs[perm[index]];
    if (swapped) {
        swap(p.first, p.second);
    }

    for (int i = start.first; i < p.first+start.first; i++) {
        for (int j = start.second; j < start.second+p.second; j++) {
                curr[i][j] = mp[perm[index]];
        }
    }
    return curr;
}
bool ans = false;

void possible(vector<int> & perm, vector<ii> & sqs, vector<vector<char>> curr, int index, ii start) {
    if (ans) {
        return;
    }
    if (index == 3) {
        int w = 0;
        int h = 0;
        for (int i = 0; i < curr.size(); i++) {
            for (int j = 0; j < curr[0].size(); j++) {
                if (curr[i][j] != '.') {
                    w = max(w, i);
                    h = max(h, j);
                }
            }
        }

        if (++w == ++h) {
            bool flag = false;
            for (int i = 0; i < w; i++) {
                for (int j = 0; j < w; j++) {
                    if (curr[i][j] == '.')
                        flag = true;
                }
            }

            if (!flag) {
                cout << w << endl;
                for (int i = 0; i < w; i++) {
                    for (int j = 0; j < w; j++) {
                        cout << curr[i][j];
                    }
                    cout << endl;
                }
                ans = true;
            }
        }
        return;
    }

    auto g = getNext(perm, sqs, curr, index, start);
    
    ii next1 = {start.first, start.second+sqs[perm[index]].second};
    ii next2 = {start.first+sqs[perm[index]].first, start.second};
    possible(perm, sqs, g, index+1, next1);
    possible(perm, sqs, g, index+1, next2);
    
    auto h = getNext(perm, sqs, curr, index, start, true);
    next1 = {start.first, start.second+sqs[perm[index]].first};
    next2 = {start.first+sqs[perm[index]].second, start.second};
    possible(perm, sqs, h, index+1, next1);
    possible(perm, sqs, h, index+1, next2);

}

int main() { _
    vector<pair<int,int>> sqs;
    int a,b;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        sqs.pb({a,b});
    }

    mp[0] = 'A';
    mp[1] = 'B';
    mp[2] = 'C';

    vector<int> perms = {0,1,2};
    do {
        vector<vector<char>> curr(304, vector<char>(304,'.'));
        possible(perms, sqs, curr,0,{0,0});

    } while (next_permutation(perms.begin(), perms.end()));

    if (!ans) {
        cout << -1 << endl;
    }

    return 0;
}