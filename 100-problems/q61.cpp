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
    // input, initialize
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    rep(e,0,m) {
        int a, b, t;
        cin >> a >> b >> t;
        a--; b--;
        dp[a][b] = t;
        dp[b][a] = t;
    }
    rep(v,0,n) dp[v][v] = 0;
    // warshall-floyd
    rep(k,0,n) {
        rep(i,0,n) {
            rep(j,0,n) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ll ans = INF;
    rep(i,0,n) {
        ll ans_i = -1;
        rep(j,0,n) ans_i = max(ans_i, dp[i][j]);
        ans = min(ans, ans_i);
    }
    cout << ans << endl;
    return 0;
}
