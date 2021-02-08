#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ll INF = LLONG_MAX;
const ld eps = 1e-14;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    p.push_back(0);
    vector<ll> q((n+1)*(n+1));
    rep(i,n+1) rep(j,n+1) q.push_back(p[i] + p[j]);
    sort(all(q));

    ll ans = 0;
    rep(i,q.size()) {
        ll q_s = m - q[i];
        ll left = 0;
        ll right = q.size();
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            ll q_mid = q[mid];
            if (q_mid > q_s) right = mid;
            else left = mid;
        }
        if (q[i] + q[right] <= m) ans = max(ans, q[i] + q[right]);
        else if (q[i] + q[left] <= m) ans = max(ans, q[i] + q[left]);
    }
    cout << ans << endl;

    return 0;
}
