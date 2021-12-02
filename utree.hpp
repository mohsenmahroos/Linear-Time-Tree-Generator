#pragma once
#include<numeric>
#include<random>
#include<vector>
#include<exception>

template<class pseudo_random_number_generator_t>
class undirected_tree: public std::vector<std::pair<size_t,size_t> > {
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
        for (size_t E = size-1, l = 1; l < size; ++l) {
            const size_t p = random_bit(random), q = 1-p;
            const size_t u = node[l-p], v = node[l-q];
            if (unordered_edges)
                emplace_back(u,v);
            else
                emplace_back(std::min(u,v),std::max(u,v));
            if (l < E) {
                const size_t i = uniform_int(0,l)(random);
                if  (i < l)
                    std::swap(node[i],node[l]);
                const size_t r = l+1, j = uniform_int(r,E)(random);
                if (j > r)
                    std::swap(node[r],node[j]); } } } };
