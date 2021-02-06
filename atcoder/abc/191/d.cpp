#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ld eps = 1e-14;

int main() {
    long double x, y, r;
    cin >> x >> y >> r;
    r += eps;
    ll ans = 0;
    for (ll i = (ll)(y-r-1); i <= (ll)(y+r+1); ++i) {
        ld p = r * r - (y - i) * (y - i);
        if (p < 0.0) continue;
        ld dx = sqrt(p + eps);
        ans += (floor(x + dx) - ceil(x - dx) + 1);
    }
    cout << ans << endl;
    return 0;
}
