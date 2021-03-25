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
    int h, w;
    cin >> h >> w;
    vector<vector<ll>> dp(10, vector<ll>(10, INF));
    rep(i,0,10) rep(j,0,10) cin >> dp[i][j];
    vector<int> a(10, 0);
    rep(i,0,h) rep(j,0,w) {
        int x;
        cin >> x;
        if (x == -1) continue;
        a[x]++;
    }
    // warshall-floyd
    rep(k,0,10) {
        rep(i,0,10) {
            rep(j,0,10) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ll ans = 0;
    rep(i,0,10) ans += dp[i][1] * a[i];
    cout << ans << endl;

    return 0;
}
