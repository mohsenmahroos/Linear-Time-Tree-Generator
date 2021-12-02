# Linear-Time-Tree-Generator

The header file utree.hpp includes a c++20 class undirected_tree. 

The class constructor has a single parameter that specifies the number of nodes in the tree.

The cycle-free tree consists of (size) distinct nodes laballed 1..size, and (size-1) distinct undirected edges (u,v) between differnt nodes u and v, such that there exists a single path between any two nodes in the tree. 

The generated tree is stored in the class object as a vector of pair of nodes. 

