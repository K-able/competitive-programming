#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind {
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {};

    int root(int x) { 
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {    
        return root(x) == root(y);
    }

    // unite y (smaller size) -> x
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // return size of group which includes x
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    UnionFind uf(7); // {0}, {1}, {2}, {3}, {4}, {5}, {6}
    uf.unite(1, 2); // {0}, {1, 2}, {3}, {4}, {5}, {6}
    uf.unite(2, 3); // {0}, {1, 2, 3}, {4}, {5}, {6}
    uf.unite(5, 6); // {0}, {1, 2, 3}, {4}, {5, 6}
    cout << uf.issame(1, 3) << endl; // True (1)
    cout << uf.issame(2, 5) << endl; // False (0)
    uf.unite(1, 6); // {0}, {1, 2, 3, 5, 6}, {4};
    cout << uf.issame(2, 5) << endl; // True (1)

    return 0;
}
