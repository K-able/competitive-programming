#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1'000'000'007;
int main() {
    int s;
    cin >> s;
    vector<ll> dp(s+1);
    dp[0] = 1;
    ll x = 0;
    for (int i = 1; i < s+1; ++i) {
        if (i - 3 >= 0) {
            x += dp[i-3];
            x %= mod;
        }
        dp[i] = x;
    }
    cout << dp[s] << endl;
    return 0;
}
