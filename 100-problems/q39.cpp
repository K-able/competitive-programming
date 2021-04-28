#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<ll>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    Matrix dp(n+1, vector<ll>(30, 0));
    dp[0][a[0]] = 1;
    rep(i,0,n-2) {
        rep(s,0,21) {
            if (dp[i][s] == 0) continue;
            if (s + a[i+1] <= 20) dp[i+1][s+a[i+1]] += dp[i][s];
            if (s - a[i+1] >= 0) dp[i+1][s-a[i+1]] += dp[i][s];
        }
    }
    cout << dp[n-2][a[n-1]] << endl;
    return 0;
}
