/*
    Algorithms for finding cycles in a directed graph
*/

#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;
#define pb push_back

vector<vi> graph(1000000);
vector<bool> visited(1000000, false);
vector<bool> recStack(1000000, false);

bool hasCycle(int n) {
    visited[n] = true;
    recStack[n] = true;

    for (auto x : graph[n]) {
        if (!visited[x]) {
            if (hasCycle(x)) {
                return true;
            }
        } else if(recStack[x]) {
            return true;
        }   
    }

    recStack[n] = false;
    return false;
}


int main() {
    // Example 1: Graph with cycle (1 -> 2 -> 3 -> 1)
    graph[1].pb(2);
    graph[2].pb(3);
    graph[3].pb(1);
    
    cout << "Example 1 (has cycle): ";
    if (hasCycle(1)) {
        cout << "Cycle found!" << endl;
    } else {
        cout << "No cycle found." << endl;
    }
    
    // Reset for next example
    fill(visited.begin(), visited.begin() + 4, false);
    fill(recStack.begin(), recStack.begin() + 4, false);
    graph[1].clear(); graph[2].clear(); graph[3].clear();
    
    // Example 2: Graph without cycle (1 -> 2 -> 3)
    graph[1].pb(2);
    graph[2].pb(3);
    
    cout << "Example 2 (no cycle): ";
    if (hasCycle(1)) {
        cout << "Cycle found!" << endl;
    } else {
        cout << "No cycle found." << endl;
    }
    
    return 0;
}