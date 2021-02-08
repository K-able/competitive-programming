#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ld eps = 1e-14;

int main() {
    ll d, n, m;
    cin >> d >> n >> m;
    vector<ll> dx(n, 0);
    for (int i = 1; i < n; ++i) cin >> dx[i];
    dx.push_back(d);
    vector<ll> k(m);
    rep(i,m) cin >> k[i];

    sort(dx.begin(), dx.end());
    ll ans = 0;
    rep(i,m) {
        int ix = lower_bound(dx.begin(), dx.end(), k[i]) - dx.begin();
        ans += min(abs(dx[ix]-k[i]), abs(dx[ix-1]-k[i]));
    }
    cout << ans << endl;

    return 0;
}
