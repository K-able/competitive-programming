#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

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

int main() {
    int q;
    cin >> q;
    vector<int> ans(q);
    rep(i,0,q) {
        string x, y;
        cin >> x >> y;
        int nx = x.size();
        int ny = y.size();
        Graph dp(1001, vector<int>(1001, 0));
        rep(i,0,nx) {
            rep(j,0,ny) {
                if (x[i] == y[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
                chmax(dp[i+1][j+1], dp[i+1][j]);
                chmax(dp[i+1][j+1], dp[i][j+1]);
            }
        }
        ans[i] = dp[nx][ny];
    }
    rep(i,0,q) cout << ans[i] << endl;
    return 0;
}
