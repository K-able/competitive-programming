#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    ll mod = 1e9+7;
    vector<vector<long>> dp(n+1, vector<long>(13));
    dp[0][0] = 1;
    rep(i,n) {
        rep(j,13) {
            if(s[i] == '?') {
                rep(k,10) {
                    dp[i+1][(j*10+k)%13] += dp[i][j];
                    dp[i+1][(j*10+k)%13] %= mod;
                }
            } else {
                ll k = s[i]-'0';
                dp[i+1][(j*10+k)%13] += dp[i][j];
                dp[i+1][(j*10+k)%13] %= mod;
            }
        }
    }
    cout << dp[n][5] << endl;
    return 0;
}
