#include "utree.hpp"
#include <iostream>
using namespace std;

int main() {
    random_device device;
    mt19937_64 random(device());
    size_t N;
    cin >> N;
    for (auto [u,v]: undirected_tree(N,random))
        cout << u << ' ' << v << endl;
    return 0; }
