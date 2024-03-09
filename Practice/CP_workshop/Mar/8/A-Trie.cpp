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

struct Trie {
    Trie* next[26];
    int words = 0;
    bool isEnd = false;
};


void insert(string a, Trie* main) {
    Trie* temp = main;
    for (int i = 0; i < a.size(); i++) {
        int num = a[i] - 'a';

        if (!temp->next[num]) {
            temp->next[num] = new Trie;
        }

        temp->words++;
        temp = temp->next[num];
    }

    temp->isEnd = true;
}
 
void dfs(set<string> & res, Trie * temp, string curr, string & word) {
    if (temp->isEnd && curr != word) {
        res.insert(curr);
    }

    for(int i = 0; i < 26; i++) {
        if (temp->next[i]) {
            dfs(res, temp->next[i], curr + char(i+'a'), word);
        } 
    }
}

void solve(string & word, set<string> & res, Trie * main) {
    Trie* temp = main;

    for (int i = 0; i < word.length(); i++) {
        int num = word[i] - 'a';
        if (!temp->next[num]) {
            cout << "No match." << endl;
            return;
        }
        temp = temp->next[num];
    }
    string curr = word;
    dfs(res, temp, curr, word);

    for (auto i : res) {
        cout << i << endl;
    }
    
    // cout << temp->words << endl;
}



int main() { _  
    int n;
    cin >> n;
    string word;

    Trie * main = new Trie;

    while (n--) {
        cin >> word;
        insert(word, main);
    }

    // cout << main->words;

    cin >> n;

    set<string> res;
    for (int i = 1; i <= n; i++) {
        cin >> word;
        cout << "Case #" << i << ": \n";
        solve(word, res , main);
        res.clear();
    }

    




    return 0;

}