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
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<int> bfs(const Graph g, int s) {
    int n = (int)g.size();
    vector<int> dist(n, -1);
    queue<int> que;
    dist[s] = 0;
    que.push(s);

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

Graph bfs_2d(const vector<string> &g, int sy, int sx) {
    int h = (int)g.size();
    int w = (int)g[0].size();
    Graph dist(h, vector<int>(w, -1));
    queue<P> que;
    dist[sy][sx] = 0;
    que.push(make_pair(sy,sx));

    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        rep(i,4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (g[ny][nx] == '#' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push(make_pair(ny,nx));
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist = bfs(g, 0);
    rep(v,n) cout << v << ": " << dist[v] << endl;
    
    return 0;
}
