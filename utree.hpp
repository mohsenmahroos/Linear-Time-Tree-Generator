#pragma once
#include<numeric>
#include<random>
#include<vector>
#include<exception>

template<class pseudo_random_number_generator_t>
class undirected_tree: public std::vector< std::pair<size_t,size_t> > {
    struct uniform_int: std::uniform_int_distribution<size_t> {
        uniform_int(size_t min, size_t max) :
            std::uniform_int_distribution<size_t>(min,max) {} };
public:
    undirected_tree(size_t size, pseudo_random_number_generator_t& random, bool unordered_edges = true) {
        if (size == 0)
            throw std::domain_error("\n undirected_tree size must be a positive number");
        std::vector<size_t> node(size);
        uniform_int random_bit(0,1);
        std::iota(node.begin(),node.end(),1);
        std::shuffle(node.begin(),node.end(),random);
        for (size_t k = 0, l = 1, m = size-1, r = 2; l < size; k = l, l = r++) {
            size_t u = node[k], v = node[l];
            if (unordered_edges) {
                if (random_bit(random))
                    std::swap(u,v);
                emplace_back(u,v); }
            else
                emplace_back(std::min(u,v),std::max(u,v));
            if (l < m) {
                const size_t i = uniform_int(0,l)(random);
                if (i < l)
                    std::swap(node[i],node[l]);
                const size_t j = uniform_int(r,m)(random);
                if (j > r)
                    std::swap(node[r],node[j]); } } } };
