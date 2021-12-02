# Linear-Time-Tree-Generator

The header file utree.hpp includes a c++20 class undirected_tree. 

The class constructor two parameters:

1. size_t size: that specifies the number of nodes in the tree.
2. pseudo_random_number_generator& random: that passed to the constructor reference to the PRNG used to generate the tree. 

The cycle-free tree consists of (size) distinct nodes laballed 1..size, and (size-1) distinct undirected edges (u,v) between differnt nodes u and v, such that there exists a single path between any two nodes in the tree. 

The generated tree is stored in the class object as a vector of (size-1) pairs of nodes that represent edges of the tree. 

