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
    vector<int> m(n+1);
    rep(i,0,n) cin >> m[i] >> m[i+1];
    Matrix dp(n+1, vector<int>(n+1, 1<<20));
    rep(i,1,n+1) dp[i][i] = 0;
    rep(i,2,n+1) {
        rep(l,1,n-i+2) {
            int r = l + i - 1;
            rep(k,l,r) chmin(dp[l][r], dp[l][k] + dp[k+1][r] + m[l-1] * m[k] * m[r]);
        }
    }
    cout << dp[1][n] << endl;
    
    return 0;
}
