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
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    int d, n;
    cin >> d >> n;
    vector<int> t(d);
    rep(i,0,d) cin >> t[i];
    vector<P> ab(n); vector<int> c(n);
    rep(i,0,n) cin >> ab[i].first >> ab[i].second >> c[i];
    Matrix dp(d+10, vector<int>(n,-1));
    rep(i,0,n) {
        if (ab[i].first > t[0] || ab[i].second < t[0]) continue;
        rep(j,0,n) {
            if (ab[j].first > t[1] || ab[j].second < t[1]) continue;
            chmax(dp[2][j], abs(c[i]-c[j]));
        }
    }
    rep(i,2,d) {
        rep(j,0,n) {
            if (dp[i][j] == -1) continue;
            rep(k,0,n) {
                if (ab[k].first > t[i] || ab[k].second < t[i]) continue;
                chmax(dp[i+1][k], dp[i][j] + abs(c[k]-c[j]));
            }
        }
    }
    int ans = 0;
    rep(i,0,n) ans = max(ans, dp[d][i]);
    cout << ans << endl;
    return 0;
}
