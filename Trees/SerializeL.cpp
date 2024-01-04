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
 
   struct TreeNode {
      int val;
      TreeNode *left;
    TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
string txt;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            txt += "n";
            return "n";
        }

        txt = txt + "s" + std::to_string(root->val) + "e";
        serialize(root->left);
        serialize(root->right);

        return txt;
    }

    vector<int> d;

    void toVec(string data) {   
        for (int i = 0; i < data.length(); i++) {
            if (data[i] == 's'){
                string temp = "";
                while (data[i+1] != 'e')
                    temp += data[++i];
                i++;
                d.push_back(stoi(temp));
            } else if (data[i] == 'n') {
                d.push_back(1005);
            }
        }
    }

    void fill(TreeNode* head, int index) {
        cout << "i: " << index-1 << "  " << d[index-1] << endl;
        if (index == d.size() - 1) return;
        

        head->val = d[index-1];
        

        if (index*2-1 < d.size() && d[index*2-1] == 1005) 
            head->left = nullptr;
        else {
            TreeNode* newL = new TreeNode(1);
            head->left = newL;
            fill(head->left, index*2);
        }


        if (index*2 < d.size() && d[index*2] == 1005) 
            head->right = nullptr;
        else{
            TreeNode* newL = new TreeNode(1);
            head->right = newL;
            fill(head->right, index*2+1);
        }

    }

    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() < 1) return nullptr;

        toVec(data);
        TreeNode* head = new TreeNode(1);
        // fill(head, 1);

        for (int i : d) {
            cout << i << " ";
        }

        return head;

    }

void traverse(TreeNode* root, int pIndex) {
        if (!root) {
            txt += 'n';
            return;
        }

        txt += to_string(root->val);
        traverse(root->left, pIndex*2);
        traverse(root->right, pIndex*2+1);
    }

    
// string serialize(TreeNode* root) {
//        txt = string()
//        traverse(root, 1);

//        return txt;
//     }

    
    

int main() { _

//    1
//   2 3
// . 4 . .
//1 2 n 4 3 n n
TreeNode* head = new TreeNode(1);
head->left = new TreeNode(2);
head->right = new TreeNode(3);
head->left->right = new TreeNode(4);

cout << serialize(head) << endl;
toVec(serialize(head));

for (int i : d) {
    cout << i << " ";
}
// TreeNode* n = deserialize(serialize(head));
// cout << "\nhead: " << n->val;
// cout << "\nleft: " << n->left->val;
// cout << "\nright: " << n->right->val;
 
return 0;
}