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
    bool visited[2005];
    bool check[2005];
    bool flag = true;
    stack<int> order;

 void topSort(int u, vector<vector<int>>& graph) {
    cout << "visited: " << u << endl;
        visited[u] = true;
        check[u] = true;

        for (auto i : graph[u]) {
            if (!visited[i])
                topSort(i, graph);
            else if (visited[i] && check[i])
                flag = false;
        }

        order.push(u);
        cout << "stack " << u << endl;
        check[u] = false;

    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses+1);
        memset(visited,false,sizeof(visited));


        for (auto i : prerequisites) {
            graph[i[0]].push_back(i[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                memset(check,false,sizeof(check));    
                topSort(i, graph);
            }
            if (!flag) {
                cout << "false";
                return {};
            }
        }

        vector<int> res;
        while (!order.empty()){
            res.push_back(order.top());
            order.pop();
        }

        return res;
        
    }

int main() { _

    vector<vector<int> > a1 = {{1,0},{2,0},{3,1},{3,2}};
    findOrder(4, a1);
 
return 0;
}