#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int m;
    cin >> m;
    vector<pair<ll, ll>> mxy(m);
    rep(i,m) cin >> mxy[i].first >> mxy[i].second;
    int n;
    cin >> n;
    vector<pair<ll, ll>> nxy(n);
    rep(i,n) {
        ll x, y;
        cin >> x >> y;
        nxy[i].first = x;
        nxy[i].second = y;
    }
    ll sx = mxy[0].first; ll sy = mxy[0].second;
    pair<ll, ll> ans;
    rep(i,n) {
        ll tx = nxy[i].first; ll ty = nxy[i].second;
        ll ans_x = tx - sx; ll ans_y = ty - sy;
        bool check_pass = true;
        rep(j,m) {
            ll move_x = mxy[j].first+ans_x; ll move_y = mxy[j].second+ans_y;
            bool flg = false;
            if (0 <= move_x && move_x < 1000001 && 0 <= move_y && move_y < 1000001) {
                rep(k,n) {
                    if (move_x == nxy[k].first && move_y == nxy[k].second) {
                        flg = true;
                        break;
                    }
                }
            }
            if (!flg) {
                check_pass = false;
                break;
            }
        }
        if (check_pass) {
            ans = make_pair(ans_x, ans_y);
            break;
        }
    }
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
