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

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> value(n);
    vector<int> weight(n);
    rep(i,0,n) cin >> value[i] >> weight[i];
    Graph dp(n+1, vector<int>(w+1, 0));
    rep(i,0,n) {
        rep(j,0,w+1) {
            if (j - weight[i] >= 0) chmax(dp[i+1][j], dp[i][j-weight[i]] + value[i]);
            chmax(dp[i+1][j], dp[i][j]);
        }
    }
    cout << dp[n][w] << endl;

    return 0;
}
