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
const ll MOD = 1e9+7;
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
    int n, m;
    cin >> n >> m;
    vector<P> ab(m);
    rep(i,0,m) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        ab[i] = {a, b};
    }
    int ans = 0;
    rep(i,0,m) {
        UnionFind uf(n);
        rep(j,0,m) {
            if (i == j) continue;
            uf.unite(ab[j].first, ab[j].second);
        }
        if(uf.size(0) != n) ans++;
    }
    cout << ans << endl;
    return 0;
}
