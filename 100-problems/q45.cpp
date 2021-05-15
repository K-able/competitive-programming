#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const ll INF = 1e9;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    vector<int> ans;
    while (true) {
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<int> c(m);
        rep(i,0,m) cin >> c[i];
        vector<int> x(n);
        rep(i,0,n) cin >> x[i];
        Matrix dp(n+1, vector<int>(256, INF));
        dp[0][128] = 0;
        rep(i,0,n) {
            rep(j,0,256) {
                rep(k,0,m) {
                    int now = j + c[k];
                    if (now > 255) now = 255;
                    else if (now < 0) now = 0;
                    int score = (x[i] - now) * (x[i] - now);
                    chmin(dp[i+1][now], dp[i][j] + score);
                }
            }
        }
        int res = INF;
        rep(i,0,256) chmin(res, dp[n][i]);
        ans.push_back(res);
    }
    rep(i,0,ans.size()) cout << ans[i] << endl;
    return 0;
}
