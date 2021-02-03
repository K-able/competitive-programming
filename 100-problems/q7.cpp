#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    cin >> n;
    vector<P> xy(n);
    vector<vector<bool>> mp(5010, vector<bool>(5010,false));
    rep(i,n) {
        int x, y;
        cin >> x >> y;
        xy[i].first = x;
        xy[i].second = y;
        mp[x][y] = true;
    }
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            int x1 = xy[i].first; int y1 = xy[i].second;
            int x2 = xy[j].first; int y2 = xy[j].second;
            int x3 = x2 + y2 - y1; int y3 = y2 + x1 - x2;
            int x4 = x1 + y2 - y1; int y4 = y1 + x1 - x2;
            if (0 <= x3 && x3 <= 5000 && 0 <= y3 && y3 <= 5000 && 0 <= x4 && x4 <= 5000 && 0 <= y4 && y4 <= 5000) {
                if (mp[x3][y3] && mp[x4][y4]) {
                    ll s = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                    ans = max(ans, s);
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
