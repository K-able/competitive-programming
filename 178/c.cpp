#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1'000'000'007;
int main() {
    int n;
    cin >> n;
    ll a = 1, b = 1, c = 1;
    rep(i,n) {
        a = (a * 10) % mod;
        b = (b * 9) % mod;
        c = (c * 8) % mod;
    }
    int ans = (a - b + mod) % mod;
    ans = (ans - b + mod) % mod;
    ans = (ans + c) % mod;
    cout << ans << endl;
    return 0;
}
