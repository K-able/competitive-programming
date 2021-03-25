#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Matrix = vector<vector<int>>;

const ll INF = 1e14;
const ld EPS = 1e-14;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    vector<vector<bool>> d(n, vector<bool>(n, false));
    rep(i,0,n) rep(j,0,n) cin >> dp[i][j];
    // warshall-floyd
    bool flg = false;
    rep(k,0,n) {
        rep(i,0,n) {
            rep(j,0,n) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) flg = true;
                if (dp[i][j] == dp[i][k] + dp[k][j] && dp[i][k] > 0 && dp[k][j] > 0) d[i][j] = true;
            }
        }
    }
    ll ans = 0;
    if (flg) ans = -1;
    else rep(i,0,n) rep(j,0,i+1) if (!d[i][j]) ans += dp[i][j];
    cout << ans << endl;
    return 0;
}
