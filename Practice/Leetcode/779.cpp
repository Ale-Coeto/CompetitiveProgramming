#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> vi;

int kthGrammar(int n, int k) {

        string start = "0";
        vector<string> v;
        v.push_back("0");
        for (int i = 0; i < n; i++) {

            
            string temp = "";
            temp += start;
            for (int i = 0; i < start.length(); i++) {
                if (start[i] == '0') {
                    temp += "1";
                } else {
                    temp += "0";
                }
            }
            start = temp;
            v.push_back(start);

        }

        cout << start;
        return (start[k-1] == '0') ? 0 : 1;

        // return -1;
    }

int main() { 
    kthGrammar(30,434991989);
    return 0;
}
    
