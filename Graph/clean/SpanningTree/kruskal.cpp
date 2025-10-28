/*
    Kruskal algorithm for finding minimum spanning tree
    using union find
    O(n log(n))
*/

#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
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

vector<pair<int,ii>> edges;
vector<pair<int, ii>> minSpanningTree;

int kruskal(int n) {

    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    int cost = 0;

    for (auto edge : edges) {
        int rootA = uf.find(edge.second.first);
        int rootB = uf.find(edge.second.second);

        if (rootA != rootB) {
            uf.unite(rootA, rootB);
            cost += edge.first;
            minSpanningTree.pb(edge);
        }

    }

    return cost;
}