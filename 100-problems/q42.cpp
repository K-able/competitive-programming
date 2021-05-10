#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const int INF = 1001001001;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n);
    vector<int> c(m);
    rep(i,0,n) cin >> d[i];
    rep(i,0,m) cin >> c[i];
    Matrix dp(n+10, vector<int>(m+10, INF));
    dp[0][0] = 0;
    rep(i,0,n) {
        rep(j,0,m) {
            chmin(dp[i][j+1], dp[i][j]);
            chmin(dp[i+1][j+1], dp[i][j] + d[i] * c[j]);
        }
    }
    int ans = INF;
    rep(j,0,m+1) chmin(ans, dp[n][j]);
    cout << ans << endl;
    return 0;
}
