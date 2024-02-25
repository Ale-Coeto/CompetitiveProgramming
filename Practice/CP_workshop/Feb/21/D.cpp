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



void solve(map<char, vi> &cards, char &trump) {

    // for (auto i : cards) {
    //     sort(i.second.begin(), i.second.end());
    // }
    sort(cards['S'].begin(), cards['S'].end());
    sort(cards['D'].begin(), cards['D'].end());
    sort(cards['C'].begin(), cards['C'].end());
    sort(cards['H'].begin(), cards['H'].end());
    
    vector<string> missing;
    vector<string> ans;
    string a, b;
    // int missing = 0;
    for (auto cardSet : cards) {
        if (cardSet.first != trump) {
        // cout << cardSet.first << " hereee \n ";
            for (int i = 0; i < cardSet.second.size(); i+=2) {
                
                if (i+1 >= cardSet.second.size()) {
                    a = to_string(cardSet.second[i]) + cardSet.first;
                    // cout << " missing " << a << endl;
                    missing.pb(a);
                    break;
                }
                a = to_string(cardSet.second[i]);
                a += cardSet.first;
                b = to_string(cardSet.second[i+1]);
                b += cardSet.first;
                // cout << " A: " << a << endl;
                ans.pb(a);
                ans.pb(b);
            }
            
        }
    }

    // cout << " missimg: " << missing.size() << " size \n";
    if (missing.size() > cards[trump].size()) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int index = 0;

    for (int i = 0; i < missing.size(); i++) {
        ans.pb(missing[i]);
        a = to_string(cards[trump][index++]);
        a += trump;
        ans.pb(a);
    }

    for (int i = index; i < cards[trump].size(); i+= 2) {
        a = to_string(cards[trump][i]);
        // cout << a << " " << endl;
        a += trump;
        b = to_string(cards[trump][i+1]);
        b += trump;
        
        ans.pb(a);
        ans.pb(b);
        
    }   

    // cout << " ans " <<  ans.size() << endl;

    for (int i = 0; i < ans.size(); i+= 2) {
        cout << ans[i] << " " << ans[i+1] << endl;
    }


}

int main() { _

    int t, n;
    char trump;
    string input;
    map<char, vi> cards;

    cin >> t;
    while (t--) {
        cin >> n >> trump;
        n*= 2;
        while (n--) {
            cin >> input;
            // cout << int(input[0] - '0') << " ";
            cards[input[1]].pb(int(input[0] - '0'));
        }

        solve(cards, trump);
        cards.clear();
    }

    return 0;
}