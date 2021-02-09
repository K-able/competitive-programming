#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int dfs(vector<vector<bool>> &mp, int y, int x) {
    if (!mp[y][x]) return 0;
    mp[y][x] = false;
    rep(i,8) dfs(mp, y+dy[i], x+dx[i]);
    return 1;
}

int main() {
    vector<int> ans;
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector<vector<bool>> mp(h+2, vector<bool>(w+2, false));
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                int ij;
                cin >> ij;
                if (ij == 1) mp[i][j] = true;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= h; ++i) {
            for (int j = 1; j <= w; ++j) {
                cnt += dfs(mp, i, j);
            }
        }
        ans.push_back(cnt);
    }
    rep(i,ans.size()) cout << ans[i] << endl;
    
    return 0;
}
