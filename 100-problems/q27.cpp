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
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int ans = 0;

void dfs(Graph &g, int y, int x, int cnt) {
    ans = max(ans, cnt);
    g[y][x] = 0;
    // for next_v that is reachable from v
    rep(i,4) {
        if (g[y+dy[i]][x+dx[i]] == 0) continue;
        dfs(g, y+dy[i], x+dx[i], cnt+1);
    }
    g[y][x] = 1;
}

int main() {
    int m, n;
    cin >> m >> n;
    Graph g(n+2, vector<int>(m+2, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i][j];
        }
    }
    rep(i,n) {
        rep(j,m) {
            if (g[i][j] == 0) continue;
            dfs(g, i, j, 1);
        }
    }
    cout << ans << endl;

    return 0;
}
