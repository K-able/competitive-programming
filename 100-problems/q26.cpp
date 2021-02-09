#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;

vector<int> ans;

void dfs_tree(const Graph &g, int v, int p = -1) {
    for (auto c : g[v]) {
        if (c == p) continue;
        ans[c] += ans[v];
        dfs_tree(g, c, v);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    Graph g(n);
    rep(i,n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans.assign(n, 0);
    rep(i,q) {
        int p, x;
        cin >> p >> x;
        --p;
        ans[p] += x;
    }
    dfs_tree(g, 0);
    rep(i,n) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
