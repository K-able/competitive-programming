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
const ll MOD = 10000;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

ll dp[110][3][3];

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ab(n+1, -1);
    rep(i,0,k) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ab[a] = b;
    }
    dp[0][0][0] = 1;
    rep(i,0,n) {
        rep(j,0,3) {
            rep(k,0,3) {
                if (ab[i] != -1) {
                    if (i >= 2 && j == k && k == ab[i]) continue;
                    dp[i+1][k][ab[i]] += dp[i][j][k];
                    dp[i+1][k][ab[i]] %= MOD;
                } else {
                    rep(l,0,3) {
                        if (i >= 2 && j == k && k == l) continue;
                        dp[i+1][k][l] += dp[i][j][k];
                        dp[i+1][k][l] %= MOD;
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(j,0,3) {
        rep(k,0,3) {
            ans += dp[n][j][k];
            ans %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
