#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> xy(n);
    rep(i,m) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        xy[x].push_back(y);
        xy[y].push_back(x);
    }
    rep(i,n) xy[i].push_back(i);
    int ans = 0;
    rep(i,1<<n) {
        vector<int> g;
        rep(j,n) {
            if ((i >> j) & 1) g.push_back(j);
        }
        bool flg = true;
        for (auto j : g) {
            for (auto k : g) {
                if (j == k) continue;
                if (find(xy[j].begin(), xy[j].end(), k) == xy[j].end()) flg = false;
            }
        }
        if (flg) {
            int g_size = g.size();
            ans = max(ans, g_size);
        }
    }
    cout << ans << endl;

    return 0;
}
