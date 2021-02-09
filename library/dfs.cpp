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

vector<bool> seen;

void dfs(const Graph &g, int v) {
    seen[v] = true;
    // for next_v that is reachable from v
    for (auto next_v : g[v]) {
        if (seen[next_v]) continue;
        dfs(g, next_v);
    }
}

void dfs_tree(const Graph &g, int v, int p = -1) {
    for (auto c : g[v]) {
        if (c == p) continue;
        dfs_tree(g, c, v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    
    seen.assign(n, false);
    rep(v,n) {
        if (seen[v]) continue;
        dfs(g, v);
    }
    return 0;
}
