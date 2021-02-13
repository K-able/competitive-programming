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

vector<vector<int>> bfs(const vector<string> &g, int sy, int sx) {
    int r = (int)g.size();
    int c = (int)g[0].size();
    vector<vector<int>> dist(r, vector<int>(c, -1));
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
    int r, c;
    cin >> r >> c;
    int sy, sx, gy, gx;
    cin >> sy >> sx;
    cin >> gy >> gx;
    --sy; --sx; --gy; --gx;
    vector<string> g(r);
    rep(i,r) cin >> g[i];
    vector<vector<int>> dist = bfs(g, sy, sx);
    cout << dist[gy][gx] << endl;
    
    return 0;
}
