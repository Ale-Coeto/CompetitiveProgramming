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

vector<int> temp;

    void print() {
        for (auto i : temp) {
            cout << i << " ";
        }

        cout << endl;
    }

        void bt(int index, vector<int> &nums, vector<vector<int>> &solution) {
        solution.push_back(temp);
        print();

        if (temp.size() == nums.size()) return;
   
        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            bt(i + 1, nums, solution);
            temp.erase(temp.begin() + temp.size() - 1);
        }

        return;

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > solution;
        solution.push_back({});
        bt(0,nums, solution);


        return solution;
    }





int main() { _
vector<int> nums{1,2,3};

subsets(nums);
 
return 0;
}