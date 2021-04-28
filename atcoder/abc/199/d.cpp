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

vector<bool> seen;
ll ans = 1;

void dfs(const Graph& g, int v, int p) {
    cout << v << endl;
    int n = g.size();
    seen[v] = true;
    int count = 3;
    rep(i,0,n) {
        if (seen[i] && *find(all(g[v]), i) == i) count--;
    }
    cout << count << endl;
    count = max(count, 0);
    ans *= count;
    for (auto next_v : g[v]) {
        if (seen[next_v]) continue;
        dfs(g, next_v, v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    seen.assign(n, false);
    rep(i,0,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(g, 0, -1);
    cout << ans << endl;
    return 0;
}
