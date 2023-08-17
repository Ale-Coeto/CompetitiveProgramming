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
 

//vector<vector<bool>> dp(10005, vector<int>(10005,false));

    bool isValid(int i, int j, vector<int>& nums) {
        if (j-i == 1 && nums[i] == nums[j]) return true;

        else if (i+1 > nums.size()) return false;

        else if (j-i == 2) {
            if ((nums[j] == nums[i] && nums[j] == nums[i+1]) || (nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[j]))
            return true;
        }

        return false;

    }

    bool traverse(vector<int>& nums, int i, int j, vector<int>& dp) {
        cout << i << " ij " << j << endl;
        if(i >= j || j >= nums.size()) return false;
        
        if(dp[i] != -1) return (dp[i] == 1)? true : false;


        if(j-i <= 2) {
            dp[i] = isValid(i,j,nums);
            cout << i << " " << j << " :" << dp[i] << endl;
            return dp[i];
        }

        dp[i] = isValid(i,i+1,nums) && traverse(nums, i+2,j,dp)? 1 : (isValid(i,i+2,nums) && traverse(nums, i+3,j,dp));
       
        return dp[i];

    }

    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        bool o = traverse(nums,0,nums.size()-1,dp);
        for (int i = 0; i < nums.size(); i++) {
                cout << dp[i] << ", ";
        }
cout << endl;
        return o;
    }

// bool isValid(int i, int j, vector<int>& nums) {
//         if (j-i == 1 && nums[i] == nums[j]) return true;

//         else if (i+1 > nums.size()) return false;

//         else if (j-i == 2) {
//             if ((nums[j] == nums[i] && nums[j] == nums[i+1]) || (nums[i]+1 == nums[i+1] && nums[i+1]+1 == nums[j]))
//             return true;
//         }

//         return false;

//     }

//     int traverse(vector<int>& nums, int i, int j, vector<int> &dp) {
//         if(i >= j || j >= nums.size()) return 0;
        
//         if(dp[i] != -1) return dp[i];


//         if(j-i <= 2) {
//             dp[i] = isValid(i,j,nums)? 1 : 0;
//             return dp[i];
//         }


//         dp[i] = (traverse(nums,i,i+1,dp) && traverse(nums, i+2,j,dp))? 1 : (traverse(nums,i,i+2,dp) && traverse(nums, i+3,j,dp));
//         return dp[i];

//     }

//     bool validPartition(vector<int>& nums) {
//         vector<int> dp(nums.size(),-1);
//         bool a = traverse(nums,0,nums.size()-1,dp) == 1? true : false;
//         for (int i = 0; i < nums.size(); i++) {
//                 cout << dp[i] << ", ";
//         }
//         cout << endl;

//         return a;
//     }

int main() { _
vector<int>  nums = {730480,730481,73082,730483,730484,730485};
cout << "ans: " << validPartition(nums) << endl;

 
return 0;
}