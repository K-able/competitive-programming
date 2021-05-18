#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const int INF = 1e9;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(110000);
    Matrix sum(20, vector<int>(110000));
    vector<int> sz(20);
    vector<int> dp(1<<20, INF);
    rep(i,0,n) {
        cin >> p[i];
        p[i]--;
        sum[p[i]][i+1]++;
        sz[p[i]]++;
    }
    rep(i,0,m) rep(j,0,n) sum[i][j+1] += sum[i][j];
    dp[0] = 0;
    rep(i,0,1<<m) {
        int pos = 0;
        rep(j,0,m) if (i & (1<<j)) pos += sz[j];
        rep(j,0,m) {
            if (i & (1<<j)) continue;
            chmin(dp[i+(1<<j)], dp[i]+sz[j]-sum[j][pos+sz[j]]+sum[j][pos]);
        }
    }
    cout << dp[(1<<m)-1] << endl;
    return 0;
}
