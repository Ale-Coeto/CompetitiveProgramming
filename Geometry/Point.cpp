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


#define MAXN 10
#define MOD 1000000007


// struct point_i { int x, y; }; // basic raw form, minimalist mode
struct point_i { 
    int x, y; // whenever possible, work with point_i
    point_i() { x = y = 0; } // default constructor
    point_i(int _x, int _y) : x(_x), y(_y) {} 
}; // user-defined

struct point { 
    double x, y; // only used if more precision is needed
    point() { x = y = 0.0; } // default constructor
    point(double _x, double _y) : x(_x), y(_y) {} 
}; // user-defined

struct point { double x, y;
point() { x = y = 0.0; }
point(double _x, double _y) : x(_x), y(_y) {}
bool operator < (point other) const { // override less than operator
if (fabs(x - other.x) > EPS) // useful for sorting
return x < other.x; // first criteria , by x-coordinate
return y < other.y; } }; // second criteria, by y-coordinate
// in int main(), assuming we already have a populated vector<point> P

//sort(P.begin(), P.end()); // comparison operator is defined above

struct point { double x, y;
point() { x = y = 0.0; }
point(double _x, double _y) : x(_x), y(_y) {}
// use EPS (1e-9) when testing equality of two floating points
bool operator == (point other) const {
return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };
// in int main()
// point P1(0, 0), P2(0, 0), P3(0, 1);
// printf("%d\n", P1 == P2); // true
// printf("%d\n", P1 == P3); // false

double dist(point p1, point p2) { // Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
return hypot(p1.x - p2.x, p1.y - p2.y); } // return double


// rotate p by theta degrees CCW w.r.t origin (0, 0)
point rotate(point p, double theta) {
double rad = DEG_to_RAD(theta); // multiply theta with PI / 180.0
return point(p.x * cos(rad) - p.y * sin(rad),
p.x * sin(rad) + p.y * cos(rad)); }

double DEG_to_RAD(double deg) {
    return deg*PI/180;
}

double RAD_to_DEG(double rad) {
    return rad*180/PI;
}
