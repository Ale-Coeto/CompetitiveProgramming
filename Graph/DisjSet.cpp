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

class UnionFind{
    private:
        vector<int> parent;
        vector<int> rank;
        int numSets;
    public:
        UnionFind(int n){
            rank.resize(n,0);
            parent.resize(n,0);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
            numSets=n;
        }
        int findSet(int i){
            return (parent[i]==i)?i : (parent[i]=findSet(parent[i]));
        }
        bool isSameSet(int i,int j){
            return findSet(i) == findSet(j);
        }
        void unionSet(int i,int j){
            if(!isSameSet(i,j)){
                int pI = findSet(i);
                int pJ = findSet(j);
                if(rank[pI] > rank[pJ]){
                    parent[pJ]=pI;
                }
                else{
                    parent[pI]=pJ;
                    if(rank[pI] == rank[pJ]){
                        rank[pJ]++;
                    }
                }
                numSets--;
            }
        }
        int getNSets(){
            return numSets;
        }
};


int main() { _

    return 0;
}