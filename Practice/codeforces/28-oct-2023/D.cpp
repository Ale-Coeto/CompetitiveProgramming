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


int unions = 0;
int sum = 0;



class DisjSet {
    int *rank, *parent, n, unions;

public:
    // Constructor to create and
    // initialize sets of n items
    DisjSet(int n) {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
        unions = 0;
        
    }

    // Creates n single item sets
    void makeSet() {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // Finds set of given item x
    int find(int x) {
        // Finds the representative of the set
        // that x is an element of
        if (parent[x] != x) {

            // if x is not the parent of itself
            // Then x is not the representative of
            // his set,
            parent[x] = find(parent[x]);

            // so we recursively call Find on its parent
            // and move i's node directly under the
            // representative of this set
        }

        return parent[x];
    }

    // Do union of two sets by rank represented
    // by x and y.
    void Union(int x, int y) {
        // Find current sets of x and y
        int xset = find(x);
        int yset = find(y);

        // If they are already in same set
        if (xset == yset)
            return;

        // Put smaller ranked item under
        // bigger ranked item if ranks are
        // different
        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }

        // If ranks are same, then increment
        // rank.
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
        unions++;
    }
};

bool greedy(vector<long> people, int c, vii &solutions) {
    int sum = people[0];
    
    for (int i = 0; i < people.size(); i++) {
        for (int j = i+1; j < people.size(); j++) {
            // if (solutions.size() == people.size())
            //     return
            if (sum+people[j] >= i+1*j+1*c) {
                sum += people[j];
                solutions.pb({i,j});
            }
            else {
                if (!solutions.empty())
                    solutions.pop_back();
            }
        }
    }
    return true;
}

void findSolutions(vii & ans, int target, int c, vector<long> &people, DisjSet set, int first, int second) {

// if (valid solution)
    if (unions == target) {
        ans.pb({first,second});

        return;
    }

    for (int i = first; i < target; i++) {
        for (int j = i+1; j < target; j++) {
            if (sum + people[j] >= i*j*c) {
                sum += people[j];
                set.Union(i,j);
                unions++;
                // solutions.pb({i,j});
                findSolutions(ans, target, c, people, set, i+1, j);
                unions--;
                // solutions.pop_back();
            }   
        }
    }


}

int main() { _

    int t, n, c;
    cin >> t;

    while (t--) {
        cin >> n >> c;
        vector<long> people;
        DisjSet set(n);
        vector<ii> ans;
        ll a;
        int size = n;
        while (n--) {
            cin >> a;
            people.pb(a);
        }
        
        // sum += 3;
        // findSolutions(ans,n,c,people,set,1,2);    
        // cout << ((ans.size() == n) ? "YES" : "NO") << endl;
        vector<ii> solutions;
        greedy(people, c, solutions);
        cout << solutions.size() << " " << size << " ";
        cout << ((solutions.size() >= size) ? "YES" : "NO") << endl;
    }

    return 0;
}