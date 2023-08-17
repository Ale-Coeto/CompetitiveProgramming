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
 

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    vector<vector<int>> graph;

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k == 0) return {target->val};

        traverse(root);
        queue<int> q;
        vector<int> ans;

        q.push(target->val);
        int count = 0;
        while(count < k) {
            
            int front = q.front();
            count++;

            for(int i = 0; i < graph[front].size(); i++) {
                if (count == k) {
                    ans.push_back(graph[front][i]);
                } else {
                    q.push(graph[front][i]);
                }
            }

        }

        return ans;
        
    }

    void traverse(TreeNode* root) {
        if(!root || (root->left == nullptr && root->right == nullptr)) return;
        
        if (root->left != nullptr) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right != nullptr){
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }
        
        traverse(root->left);
        traverse(root->right);
        
    }

};

int main() { _

return 0;
}