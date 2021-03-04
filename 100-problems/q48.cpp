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

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i,0,n) cin >> w[i];
    Matrix dp(n+1, vector<int>(n+1, 0));
    rep(i,2,n+1) {
        rep(l,0,n) {
            int r = l + i;
            if (r > n) continue;
            if (abs(w[l] - w[r-1]) <= 1 && dp[l+1][r-1] == i - 2) chmax(dp[l][r], i);
            rep(m,l,r+1) chmax(dp[l][r], dp[l][m] + dp[m][r]);
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}
