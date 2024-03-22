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
using ll = long long;

struct Node {
  map<char, ll> next;
  bool end = false;
};

vector<Node> trie;
ll trieSize = 0;

ll newNode() {
  trie.push_back(Node());
  return trieSize++;
}

void add(string& s) {
  ll pt = 0;

  for(ll i = 0; i < s.size(); i++) {
    if(not trie[pt].next.count(s[i]))
      trie[pt].next[s[i]] = newNode();

    pt = trie[pt].next[s[i]];
  }

  trie[pt].end = true;
}

ll dfs(ll u, string& s, ll ps = 0) {
  if(ps == s.size())
    return u;

  if(trie[u].next.count(s[ps]))
    return dfs(trie[u].next[s[ps]], s, ps + 1);

  return -1;
}

int main() { _

    return 0;
}