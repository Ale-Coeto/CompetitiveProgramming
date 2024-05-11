# Graph Algorithms

## Table of Contents
- [Graph Representation](#graph-representation)


## Graph Traversal

### Breadth First Search (BFS)
Traverse the graph level by level. It uses a queue to store the nodes to be visited.
- [BFS on a Graph](BFS.cpp)

### Depth First Search (DFS)
Traverse the graph by going as deep as possible. It uses a stack to store the nodes to be visited.
- [DFS on a Graph](DFS.cpp)

### Topological Sort
Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge `uv`, vertex `u` comes before `v` in the ordering.
- [Topological Sort](TopologicalSort.cpp)

### Bipartite Graph
A bipartite graph is a graph whose vertices can be divided into two disjoint sets `U` and `V` such that every edge connects a vertex in `U` to one in `V`.
- [Bipartite Graph](BipartiteCheck.cpp)

### Articulation Points and Bridges
Articulation points and bridges when removed disconnect the graph.
- [Articulation Points and Bridges](Articulation&Bridges.cpp)


## Minimum Spanning Tree
A minimum spanning tree is a subset of the edges of a connected, edge-weighted graph that connects all the vertices together, without any cycles and with the minimum possible total edge weight.

### Kruskal's Algorithm
Kruskal's algorithm is a minimum-spanning-tree algorithm which finds an edge of the least possible weight that connects any two trees in the forest.
- [Kruskal's Algorithm](Kruskal.cpp)

### Prim's Algorithm
Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph.
- [Prim's Algorithm](Prim.cpp)


## Single source Shortest Path Algorithms

### Dijkstra's Algorithm
Dijkstra's algorithm is an algorithm for finding the shortest paths between 1 node and the rest of the nodes in a graph.
- [Dijkstra's Algorithm](Dijkstra.cpp)

### Bellman-Ford Algorithm
Finds the shortest path from a single source vertex to all other vertices in a weighted graph that can have negative weights.

- [Bellman-Ford Algorithm](BellmanFord.cpp)


## All Pairs Shortest Path Algorithms

### Floyd-Warshall Algorithm
Floyd-Warshall algorithm is an algorithm for finding the shortest paths between all pairs of vertices in a weighted graph with positive or negative edge weights (but with no negative cycles).

- [Floyd-Warshall Algorithm](FloydWarshall.cpp)


## Flow

### Ford-Fulkerson Algorithm
Ford-Fulkerson algorithm is a greedy algorithm that computes the maximum flow in a flow network.
- [Ford-Fulkerson Algorithm](FordFulker.cpp)

## Disjoint Set Union (DSU)
Disjoint Set Union (DSU) is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
- [Disjoint Set Union (DSU)](DisjSet.cpp)

## Trie
A trie is a tree-like data structure whose nodes store the letters of an alphabet. By structuring the nodes in a particular way, words and strings can be retrieved from the structure by traversing down a branch path of the tree.

- [Trie](Trie.cpp)

