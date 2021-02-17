#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
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

Graph bfs_2d(const Graph lw, const Graph uw, int sh, int sw) {
    int h = (int)lw.size();
    int w = (int)lw[0].size();
    Graph dist(h, vector<int>(w, -1));
    queue<P> que;
    dist[sh][sw] = 1;
    que.push(make_pair(sh,sw));

    while (!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        rep(i,0,4) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;
            if (dist[ny][nx] != -1) continue;
            if ((i == 0 && uw[ny][nx] == 1) || (i == 1 && lw[ny][nx] == 1) || (i == 2 && uw[y][x] == 1) || (i == 3 && lw[y][x] == 1)) continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push(make_pair(ny,nx));
        }
    }
    return dist;
}

int main() {
    vector<int> ans;
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        Graph left_wall(h, vector<int>(w, 0));
        Graph up_wall(h, vector<int>(w, 0));
        rep(i,0,2*h-1) {
            if (i % 2 == 0) {   // left wall
                rep(j,0,w-1) cin >> left_wall[i/2][j+1];
            } else {    // right wall
                rep(j,0,w) cin >> up_wall[i/2+1][j];
            }
        }
        Graph dist = bfs_2d(left_wall, up_wall, 0, 0);
        int ans_i = dist[h-1][w-1] == -1 ? 0 : dist[h-1][w-1];
        ans.push_back(ans_i);
    }
    rep(i,0,ans.size()) cout << ans[i] << endl;
    return 0;
}
