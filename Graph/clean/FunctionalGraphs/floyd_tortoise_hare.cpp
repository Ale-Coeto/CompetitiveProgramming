/*
    Floyd Algorithm for finding cycles in a functional graph
    Also known as Tortoise & Hare
    O(N) time, O(1) space
*/

#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> vi;
#define pb push_back

// Find the start node of a cycle
int findStartOfCycle(int n, vi & succ) {
    int a = succ[n];
    int b = succ[succ[n]];

    while (a != b) {
        a = succ[a];
        b = succ[succ[b]];
    }
    a = n;
    while (a != b) {
        a = succ[a];
        b = succ[b];
    }
    return a;
}

int main() { 
    // For test1: Succesor of 1=2, 2=3, ..., 6=4
    vi test1 = {0,2,3,4,5,6,4};
    vi test2 = {0,2,4,3,1,4};

    cout << "TEST1 from 1: " << findStartOfCycle(1,test1) << endl;
    cout << "TEST1 from 1: " << findStartOfCycle(5,test1) << endl;
    cout << "TEST2 from 1: " << findStartOfCycle(1,test2) << endl;

    return 0;
}