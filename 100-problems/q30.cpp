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

Graph bfs_2d(const vector<vector<char>> &g, int sy, int sx) {
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
            if (g[ny][nx] == 'X' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push(make_pair(ny,nx));
        }
    }
    return dist;
}

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<char>> g(h+2, vector<char>(w+2, 'X'));
    vector<P> numbers(n+1);
    for (int i = 1; i < h+1; ++i) {
        for (int j = 1; j < w+1; ++j) {
            char c;
            cin >> c;
            if (c == 'S') numbers[0] = {i, j};
            if (0 < (int)(c - '0') && (int)(c - '0') <= 9) numbers[(int)(c - '0')] = {i, j};
            g[i][j] = c;
        }
    }
    int ans = 0;
    rep(i,n) {
        Graph dist = bfs_2d(g, numbers[i].first, numbers[i].second);
        ans += dist[numbers[i+1].first][numbers[i+1].second];
    }
    cout << ans << endl;
    
    return 0;
}
