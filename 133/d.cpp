#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll x1 = 0;
    int code = 1;
    rep(i,n) {
        x1 += a[i] * code;
        code *= -1;
    }
    vector<ll> ans(n);
    ans[0] = x1;
    for (int i = 1; i < n; i++) {
        ans[i] = 2 * a[i-1] - ans[i-1];
    }
    rep(i,ans.size()) {
        printf("%d%c", ans[i], i+1==ans.size()?'\n':' ');
    }
    return 0;
}
