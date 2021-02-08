#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = LLONG_MAX;
    rep(i,1<<n) {
        vector<ll> a_copy(n);
        copy(a.begin(), a.end(), a_copy.begin());
        int bit[n];
        int sum = 0;
        ll cnt = 0;
        rep(j,n) {
            int div = (1 << j);
            bit[j] = (i / div) % 2;
            sum += bit[j];
        }
        if (sum != k) continue;
        for (int j = 1; j < n; ++j) {
            if (bit[j] == 0) continue;
            ll m = *max_element(a_copy.begin(), a_copy.begin()+j);
            if (m >= a_copy[j]) {
                ll d = m - a_copy[j] + 1;
                a_copy[j] += d;
                cnt += d;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
