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

// {w(e), {u, v}} (e = (u, v))
using Edge = pair<double, P>;

int main() {
    vector<int> n_list(10000);
    vector<vector<tuple<double, double, double, double>>> xyzr_list(10000);
    int count = 0;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        n_list[count] = n;
        vector<tuple<double, double, double, double>> xyzr(n);
        rep(i,0,n) {
            double x, y, z, r;
            cin >> x >> y >> z >> r;
            xyzr[i] = make_tuple(x, y, z, r);
        }
        xyzr_list[count++] = xyzr;
    }
    rep(c,0,count) {
        int n = n_list[c];
        vector<tuple<double, double, double, double>> xyzr = xyzr_list[c];
        int m = n * (n - 1) / 2;
        vector<Edge> edges(m);
        int index = 0;
        rep(i,0,n) {
            rep(j,0,n) {
                if (i >= j) continue;
                double xi = get<0>(xyzr[i]); double xj = get<0>(xyzr[j]);
                double yi = get<1>(xyzr[i]); double yj = get<1>(xyzr[j]);
                double zi = get<2>(xyzr[i]); double zj = get<2>(xyzr[j]);
                double ri = get<3>(xyzr[i]); double rj = get<3>(xyzr[j]);
                double dist = sqrtl(powl((xi - xj), 2) + powl((yi - yj), 2) + powl((zi - zj), 2));
                double w = max(dist - (ri + rj), 0.0);
                edges[index++] = Edge(w, make_pair(i, j));
            }
        }
        sort(all(edges));
        // kruskal
        double res = 0;
        UnionFind uf(n);
        rep(i,0,m) {
            double w = edges[i].first;
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            if (uf.issame(u,v)) continue;
            res += w;
            uf.unite(u,v);
        }
        cout << fixed << setprecision(3) << res << endl;
    }
    return 0;
}
