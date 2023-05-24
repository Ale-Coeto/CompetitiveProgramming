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

struct Point {
    ll x,y;
};

int orientation(Point p1, Point p2, Point p3) {
    ll val = (p2.y-p1.y)*(p3.x-p2.x)-(p3.y-p2.y)*(p2.x-p1.x);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

int orientation(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll val = (y2-y1)*(x3-x2)-(y3-y2)*(x2-x1);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

bool onSegment(Point p, Point q, Point r) {
    if (r.x <= max(p.x,q.x) && r.x >= min(p.x,q.x) && 
    r.y <= max(p.y,q.y) && r.y >= min(p.y,q.y))
       return true;
  
    return false;
}

bool compare(Point a, Point b, Point c, Point d) {
    
    int ans1 = orientation(a.x,a.y,b.x,b.y,c.x,c.y);
    int ans2 = orientation(a.x,a.y,b.x,b.y,d.x,d.y);
    int ans3 = orientation(c.x,c.y,d.x,d.y,a.x,a.y);
    int ans4 = orientation(c.x,c.y,d.x,d.y,b.x,b.y);

    

        if ((ans1 == 0) && onSegment(a,b,c)) return true;
        else if ((ans2 == 0) && onSegment(a,b,d)) return true;
        else if ((ans3 == 0) && onSegment(c,d,a)) return true;
        else if ((ans4 == 0) && onSegment(c,d,b)) return true;
        else if (ans1 != ans2 && ans3 != ans4)
            return true;
        else 
            return false;
    
}

int main() { _
    int t;
    ll x1,y1,x2,y2,x3,y3,x4,y4;
    bool a;
    cin >> t;
    //string res[] = {"TOUCH","RIGHT","LEFT"};
    string intersect[] = {"NO", "YES"};
    

    FOR(i,0,t) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        Point p1 = {x1,y1}, p2 = {x2,y2}, p3 = {x3,y3}, p4 = {x4,y4};

        //ans1 = orientation(p1,p2,p3);
          
        a = compare(p1,p2,p3,p4);

        cout << intersect[a] << "\n";
        //cout << res[ans1] << "\n";
    }

    return 0;
}