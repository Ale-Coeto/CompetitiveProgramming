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

     stack<int> sortS;
    int visited[2005];

    void topSort(int u, vector<vector<int> > &graph) {
        visited[u] = 1;

        for (int i = 0; i < graph[u].size(); i++) {
            if (visited[graph[u][i]] == -1)
                topSort(graph[u][i], graph);
        }
        sortS.push(u);
        cout << "S" << u << endl;
    }

    bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        //if (prerequisites.size() == 1) return true;

        vector<vector<int>> graph(numCourses+5);
        memset(visited,-1,sizeof(visited));

        for (int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == -1)
                topSort(i, graph);
        }

        if(sortS.size() != numCourses)
            return false;

        return true;


    }




int main() { _
    vector<vector<int> > a = {{1,0},{0,1}};
    vector<vector<int> > a1 = {{1,0},{2,1}};
    cout << canFinish(2, a);

return 0;
}