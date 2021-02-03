#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> ab(n);
    for (auto& [a, b] : ab) cin >> a >> b;
    ll ans = LLONG_MAX;
    rep(i,n) {
        rep(j,n) {
            ll start = ab[i].first;
            ll end = ab[j].second;
            ll time = 0;
            rep(k,n) {
                ll a = ab[k].first;
                ll b = ab[k].second;
                time += abs(a - start) + abs(a - b) + abs(b - end);
            }
            ans = min(ans, time);
        }
    }
    cout << ans << endl;

    return 0;
}
