#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const ll INF = 1e16;
const ld EPS = 1e-14;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

P bit_dp(const vector<vector<P>> dt, vector<vector<P>>& dp, int bit, int v) {
    int n = dt.size();
    if (bit == (1<<n)-1) {
        if (v == 0) return dp[bit][v] = P(0, 1);
        else return dp[bit][v] = P(INF, 0);
    }
    if (dp[bit][v].first > 0) return dp[bit][v];
    P res = P(INF, 0);
    rep(u,0,n) {
        if (bit & (1<<u)) continue;
        if (dt[v][u].second == 0) continue;
        P r = bit_dp(dt, dp, (bit | (1<<u)), u);
        r.first += dt[v][u].first;
        if (r.first <= dt[v][u].second) {
            if (res.first > r.first) res = r;
            else if (res.first == r.first) res.second += r.second;
        }
    }
    return dp[bit][v] = res;
}

int main() {
    int n, m;
    cin >> n >> m;
    // P(dist, time)
    vector<vector<P>> dt(n, vector<P>(n, P(0,0)));
    rep(i,0,m) {
        ll s, t, d, time;
        cin >> s >> t >> d >> time;
        --s; --t;
        dt[s][t] = P(d, time);
        dt[t][s] = P(d, time);
    }
    // P(dist, num of cases)
    vector<vector<P>> dp((1<<n)+1, vector<P>(n+1, P(0, 0)));
    dp[0][0] = P(0, 0);
    P ans = bit_dp(dt, dp, 0, 0);
    if (ans == P(INF, 0)) cout << "IMPOSSIBLE" << endl;
    else cout << ans.first << " " << ans.second << endl;

    return 0;
}
