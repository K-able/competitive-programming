#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i,n) rep(j,m) cin >> a[i][j];
    ll ans = 0;
    for (int i = 0; i < m-1; ++i) {
        for (int j = i+1; j < m; ++j) {
            ll cnt = 0;
            rep(k,n) cnt += max(a[k][i], a[k][j]);
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}
