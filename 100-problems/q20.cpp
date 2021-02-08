#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ld eps = 1e-14;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> abc(3, vector<ll>(n));
    rep(i,3) rep(j,n) cin >> abc[i][j];
    rep(i,3) sort(abc[i].begin(), abc[i].end());
    
    ll ans = 0;
    for (auto b : abc[1]) {
        ll a_num = lower_bound(abc[0].begin(), abc[0].end(), b) - abc[0].begin();
        ll c_num = n - (upper_bound(abc[2].begin(), abc[2].end(), b) - abc[2].begin());
        ans += a_num * c_num;
    }
    cout << ans << endl;

    return 0;
}
