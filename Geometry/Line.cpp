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

//POINT ______________________________________________________________________-
// Point int // basic raw form, minimalist mode
struct point_i { 
    int x, y; // whenever possible, work with point_i
    point_i() { x = y = 0; } // default constructor
    point_i(int _x, int _y) : x(_x), y(_y) {} 
}; // user-defined

//Point double
struct point { 
    double x, y; // only used if more precision is needed
    point() { x = y = 0.0; } // default constructor
    point(double _x, double _y) : x(_x), y(_y) {} 
}; // user-defined

// For sorting points
struct point { double x, y;
point() { x = y = 0.0; }
point(double _x, double _y) : x(_x), y(_y) {}
bool operator < (point other) const { // override less than operator
if (fabs(x - other.x) > EPS) // useful for sorting
return x < other.x; // first criteria , by x-coordinate
return y < other.y; } }; // second criteria, by y-coordinate
// in int main(), assuming we already have a populated vector<point> P

//sort(P.begin(), P.end()); // comparison operator is defined above

//For comparing points
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

//Euclidean distance
double dist(point p1, point p2) { // Euclidean distance
// hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
return hypot(p1.x - p2.x, p1.y - p2.y); } // return double


// Rotate point by theta degrees CCW w.r.t origin (0, 0)
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

//LINE ______________________________________________________________________-
//Line ax + by + c = 0
struct line { double a, b, c; }; // a way to represent a line

// Make line with 2 points (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
l.a = 1.0; l.b = 0.0; l.c = -p1.x; // default values
} else {
l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
l.c = -(double)(l.a * p1.x) - p1.y;
} }

//Check if parallel
bool areParallel(line l1, line l2) { // check coefficients a & b
return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); }

//Check if equal
bool areSame(line l1, line l2) { // also check coefficient c
return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS); }

// Check if 2 lines intersect -> returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
if (areParallel(l1, l2)) return false; // no intersection
// solve system of 2 linear algebraic equations with 2 unknowns
p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
// special case: test for vertical line to avoid division by zero
if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
else p.y = -(l2.a * p.x + l2.c);
return true; }

//Vector ______________________________________________________________________-
struct vec { double x, y; // name: ‘vec’ is different from STL vector
vec(double _x, double _y) : x(_x), y(_y) {} };
vec toVec(point a, point b) { // convert 2 points to vector a->b
return vec(b.x - a.x, b.y - a.y); }
vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
return vec(v.x * s, v.y * s); } // shorter.same.longer
point translate(point p, vec v) { // translate p according to v
return point(p.x + v.x , p.y + v.y); }

//Dot product
double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
// formula: c = a + u * ab
vec ap = toVec(a, p), ab = toVec(a, b);
double u = dot(ap, ab) / norm_sq(ab);
c = translate(a, scale(ab, u)); // translate a to c
return dist(p, c); } // Euclidean distance between p and c