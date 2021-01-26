#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int>(n,100));
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 1;
    }
    rep(i,n) dp[i][i] = 0;

    rep(k,n) {
        rep(i,n) {
            rep(j,n) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    int ans = 0;
    rep(i,n) {
        if (dp[i][i] = 0) ans += 1;
    }
    ans = n - ans;
    cout << ans << endl;

    return 0;
}
