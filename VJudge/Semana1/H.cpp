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
 
int main() { _

    return 0;
}


// Input
// The input file contains at most 1000 lines. Each line consists of either one comparison or two comparisons
// separated by logical and operator “&&”. Each comparison starts with “x”, followed by greater-or-equals
// operator “>=” or less-or-equals operator “<=”, followed by an integer constant. When two comparisons
// are in the same line, the first one is always greater-or-equals, followed by less-or-equals.
// All lines, but the last one, are terminated by logical or operator “||”. All tokens in a line are separated
// by a single space and there are no trailing or leading spaces.
// Output
// Write the refactored expression to the output file in the same format as in the input. You can arrange lines
// in any order, as long as the resulting expression has the right format, produces the same Boolean result
// on all integers x, and contains the minimal possible number of integer constants in its text. Numbers
// must be formatted without leading zeros and there must be precisely one space between tokens on a line.
// Write a single line with the word “true” if the expression is true on all integers. Write a single line with
// the word “false” if the expression is false on all integers.

// x >= 5 && x <= 10 ||
// x >= 7 && x <= 20 ||
// x <= 2 ||
// x >= 21 && x <= 25 ||
// x >= 8 && x <= 10 ||
// x >= 100

// x <= 2 ||
// x >= 5 && x <= 25 ||
// x >= 100



// x >= 10 && x <= 0 false

// x <= 10 ||


// x >= 0

// true


// x >= -32768 
//true