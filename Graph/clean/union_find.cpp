/*
    Data structure for connected components
    Union-Find / Disjoint set
*/

#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> vi;
#define pb push_back

struct UnionFind {
    private: 
        vi parent;
        vi height; // Can use height of the tree as rank
        vi size;   // Or size (number of components in a set)
        int components;
        int largestSize;

    public:
        UnionFind(int n) {
            parent.resize(n+1,0);
            height.resize(n+1,0);
            size.resize(n+1,1);

            for (int i = 1; i <= n; i++) {
                parent[i] = i;
            }
            components = n;
            largestSize = 1;
        }

        // Find the root/representative of a node
        int find(int a) {
            if (parent[a] != a) {
                parent[a] = find(parent[a]);
            }
            return parent[a];
        }

        // Check if two nodes are connected
        bool isConnected(int a, int b) {
            return find(a) == find(b);
        }

        // Unite two nodes
        void unite(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);

            if (rootA != rootB) {
                // Always append the smaller tree to the larger one (could use height instead)
                if (size[rootA] < size[rootB]) {
                    swap(rootA, rootB);
                }
                parent[rootB] = rootA;
                size[rootA] += size[rootB];
                largestSize = max(largestSize, size[rootA]);

                // // Unconmment this if using height
                // if (height[rootA] == height[rootB]) {
                //     height[rootA]++;
                // }
                components--;
            }
        }

        // Number of components/sets
        int getComponents() {
            return components;
        }

        // Size of the largest set
        int getLargestSize() {
            return largestSize;
        }

        // Get size of the set that a belongs to
        int getSize(int a) {
            int root = find(a);
            return size[root];
        }

};

int main() { 
    // Example with 5 nodes
    UnionFind uf(5);
    
    cout << "Initial components: " << uf.getComponents() << endl;
    cout << "Initial largest size: " << uf.getLargestSize() << endl;
    
    // Connect 1-2 and 3-4
    uf.unite(1, 2);
    cout << "After unite(1,2): " << uf.getComponents() << " components" << endl;
    
    uf.unite(3, 4);
    cout << "After unite(3,4): " << uf.getComponents() << " components" << endl;
    
    // Check connections
    cout << "Are 1 and 2 connected? " << (uf.isConnected(1, 2) ? "Yes" : "No") << endl;
    cout << "Are 1 and 3 connected? " << (uf.isConnected(1, 3) ? "Yes" : "No") << endl;
    
    // Connect the two components
    uf.unite(2, 3);
    cout << "After unite(2,3): " << uf.getComponents() << " components" << endl;
    cout << "Largest component size: " << uf.getLargestSize() << endl;
    cout << "Size of component containing 1: " << uf.getSize(1) << endl;
    
    return 0;
}