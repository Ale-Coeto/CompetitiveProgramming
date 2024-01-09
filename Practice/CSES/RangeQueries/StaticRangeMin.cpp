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
 
#define MAXN 200005
#define MOD 1000000007
int memo[200][200];

//DP Aproach (TL)
int dp(vector<long> &nums, int a, int b) {    

    if (memo[a][b]) return memo[a][b];

    if (b-a == 1)  return min(nums[a],nums[b]);

    if (b-a == 0) return nums[a];

    int mid = a + (b-a)/2;
    memo[a][b] = min(dp(nums,a,mid),dp(nums,mid+1,b));
    return memo[a][b];

}

vector<long> st;

long makeSegmenTree(vector<u_int64_t> &nums, u_int64_t index, u_int64_t left, u_int64_t right) {
    if (left == right) {
        st[index] = nums[left];
        return st[index];
    }

    int mid = left + (right-left)/2;
    st[index] = min(makeSegmenTree(nums, index*2+1, left, mid), makeSegmenTree(nums,index*2+2, mid+1, right));
    return st[index];
}

//0-2
long find(u_int64_t left, u_int64_t right, u_int64_t targetL, u_int64_t targetR, u_int64_t index) { //2-4 //0,7  //0-3 // 2-3
    if (left > targetR || right < targetL) return MAXN;
    if (left >= targetL && right <= targetR) return st[index];
    
    u_int64_t mid = left + (right-left)/2; //1

    return min(find(left,mid,targetL,targetR,index*2+1), find(mid+1,right,targetL,targetR,index*2+2));

}

int main() { _
    u_int64_t n,q,a,b;
    long x;
    vector<u_int64_t> nums;

    cin >> n >> q;
    u_int64_t size = n;

    while (n--) {
        cin >> x;
        nums.pb(x);
    }

     n = size*2;
     st.assign(n-1,-1);

    makeSegmenTree(nums,0,0,size-1);
    

    while (q--) {
        cin >> a >> b;
        cout << (find(0,size-1,a-1,b-1,0)) << endl;
    }

 
return 0;
}