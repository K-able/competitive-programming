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
    int n, m;
    cin >> n >> m;
    vector<int> c(m);
    rep(i,0,m) cin >> c[i];
    vector<ll> dp(n+1, INF);
    dp[0] = 0;
    rep(i,0,m) {
        rep(j,0,n+1) {
            if (j+c[i] <= n) chmin(dp[j+c[i]], dp[j]+1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
