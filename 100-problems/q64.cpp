#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

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
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }
    int size(int x) {
        return siz[root(x)];
    }
};

using Edge = pair<int, P>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    rep(i,0,m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u,v));
    }
    sort(all(edges));
    ll res = 0;
    UnionFind uf(n);
    rep(i,0,m) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (uf.issame(u,v)) continue;
        res += w;
        uf.unite(u,v);
    }
    cout << res << endl;
    return 0;
}
