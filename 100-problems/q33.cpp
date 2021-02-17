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

Graph bfs_2d(const vector<string> &g, int sy, int sx) {
    int h = (int)g.size();
    int w = (int)g[0].size();
    Graph dist(h, vector<int>(w, -1));
    queue<P> que;
    dist[sy][sx] = 1;
    que.push(make_pair(sy,sx));

    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        rep(i,4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
            if (g[ny][nx] == '#' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push(make_pair(ny,nx));
        }
    }
    return dist;
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i,h) cin >> g[i];
    int white_num = 0;
    rep(i,h) rep(j,w) if (g[i][j] == '.') ++white_num;
    
    Graph dist = bfs_2d(g, 0, 0);
    int ans = dist[h-1][w-1] != -1 ? white_num - dist[h-1][w-1] : -1;
    cout << ans << endl;
    
    return 0;
}
