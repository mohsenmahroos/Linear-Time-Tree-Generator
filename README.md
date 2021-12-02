# Linear-Time-Tree-Generator

The header file utree.hpp includes a c++20 class undirected_tree. 

The class constructor has a single parameter that specifies the number of nodes in the tree.

The generated tree is stored in the class object as a vector of pair of node numbers in the range 1..size. 

The tree consists of (size-1) edges (u,v), such that there exists a single path between any two nodes in the tree. 
