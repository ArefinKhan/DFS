# DFS (Iterative using Stack) and Topological Sort

In this C++ implementation, we do the following:

1. We build an adjacency list following a list of edges. All edges are directed, meaning that {2,5} represents an edge where 2 is the source node and 5 is the destination node.
2. We run an iterative DFS on the directed graph. When we finish visiting a node, we insert that node in a stack. 
3. The order in the stack is the topological ordering of the nodes in our graph.
