#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;

vector<int> seen;
vector<int> finish;
int timestamp = 0;

void dfs(const vector<vector<int>> &g, int v) {
    if (seen[v] == 0) seen[v] = ++timestamp;
    // for next_v that is reachable from v
    for (auto next_v : g[v]) {
        if (seen[next_v]) continue;
        dfs(g, next_v);
    }
    finish[v] = ++timestamp;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    rep(i,n) {
        int v, k;
        cin >> v >> k;
        rep(j,k) {
            int u;
            cin >> u;
            u--;
            g[i].push_back(u);
        }
    }
    // search
    seen.assign(n, 0);
    finish.assign(n, 0);
    rep(v,n) {
        if (seen[v]) continue;
        dfs(g, v);
    }
    rep(v,n) cout << v+1 << " " << seen[v] << " " << finish[v] << endl;
    return 0;
}
