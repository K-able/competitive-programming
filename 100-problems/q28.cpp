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

vector<int> bfs(const Graph &g, int s) {
    int n = (int)g.size();
    vector<int> dist(n, -1);
    queue<int> que;
    dist[0] = 0;
    que.push(0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int x : g[v]) {
            if (dist[x] != -1) continue;
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main() {
    int n;
    cin >> n;
    Graph g(n);
    rep(i,n) {
        int u, k;
        cin >> u >> k;
        rep(j,k) {
            int v;
            cin >> v;
            --v;
            g[i].push_back(v);
        }
    }
    vector<int> dist = bfs(g, 0);
    rep(v,n) cout << v+1 << " " << dist[v] << endl;
    
    return 0;
}
