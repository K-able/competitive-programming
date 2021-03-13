#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int solve(const Matrix c, vector<int> &dp, int s) {
    cout << "check" << endl;
    if (dp[s] != -1) return dp[s];
    rep(i,0,10) {
        chmin(dp[s], solve(c, dp, i) + c[s][i]);
    }
    return dp[s];
}

int main() {
    int h, w;
    cin >> h >> w;
    Matrix c(10, vector<int>(10));
    rep(i,0,10) rep(j,0,10) cin >> c[i][j];
    Matrix a(h, vector<int>(w));
    rep(i,0,h) rep(j,0,w) cin >> a[i][j];
    vector<int> dp(11, -1);
    ll ans = 0;
    cout << "check" << endl;
    rep(i,0,h) {
        rep(j,0,w) {
            cout << j << " " << a[i][j] << endl;
            if (a[i][j] == -1) continue;
            else ans += solve(c, dp, a[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
