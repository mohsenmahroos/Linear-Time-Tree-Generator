#include "utree.hpp"
#include <iostream>
using namespace std;

int main() {
    size_t N;
    cin >> N;
    for (auto [u,v]: undirected_tree(N))
        cout << u << ' ' << v << endl;
    return 0; }
