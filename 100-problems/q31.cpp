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
int dx1[6] = {0, 1, 0, -1, 1, 1};
int dx2[6] = {0, 1, 0, -1, -1, -1};
int dy[6] = {1, 0, -1, 0, 1, -1};

Graph bfs_2d(const Graph &g, int sy, int sx) {
    int h = (int)g.size();
    int w = (int)g[0].size();
    Graph reach(h, vector<int>(w, -1));
    queue<P> que;
    reach[sy][sx] = 0;
    que.push(make_pair(sy,sx));

    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        rep(i,6) {
            int ny; int nx;
            if (y % 2 == 1) {
                ny = y + dy[i];
                nx = x + dx1[i];
            } else {
                ny = y + dy[i];
                nx = x + dx2[i];
            }
            if (ny < 0 || ny > h-1 || nx < 0 || nx > w-1) continue;
            if (g[ny][nx] == 1 || reach[ny][nx] != -1) continue;
            reach[ny][nx] = 0;
            que.push(make_pair(ny,nx));
        }
    }
    return reach;
}

int main() {
    int h, w;
    cin >> w >> h;
    Graph g(h+2, vector<int>(w+2, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            cin >> g[i][j];
        }
    }
    Graph reach = bfs_2d(g, 0, 0);
    int ans = 0;
    rep(i,h+2) {
        rep(j,w+2) {
            if (g[i][j] == 0) continue;
            int cnt = 0;
            rep(k,6) {
                int ni, nj;
                if (i % 2 == 1) {
                    ni = i + dy[k];
                    nj = j + dx1[k];
                } else {
                    ni = i + dy[k];
                    nj = j + dx2[k];
                }
                if (reach[ni][nj] != -1) cnt++;
            }
            ans += cnt;
        }
    }
    cout << ans << endl;    
    return 0;
}
