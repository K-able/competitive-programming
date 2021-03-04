#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const int INF = 1<<20;
const ld EPS = 1e-14;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int bit_dp(const Matrix dist, Matrix& dp, int bit, int v) {
    int n = dist.size();
    if (dp[bit][v] >= 0) return dp[bit][v];
    if (bit == (1<<n)-1 && v == 0) return dp[bit][v] = 0;
    int res = INF;
    rep(u,0,n) {
        if (dist[v][u] == INF) continue;
        if (!(bit & (1<<u))) chmin(res, bit_dp(dist, dp, (bit | (1<<u)), u) + dist[v][u]);
    }
    return dp[bit][v] = res;
}

int main() {
    int v, e;
    cin >> v >> e;
    Matrix dist(v, vector<int>(v, INF));
    rep(i,0,e) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    Matrix dp(1<<v+1, vector<int>(v+1, -1));
    int ans = bit_dp(dist, dp, 0, 0);
    if (ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
