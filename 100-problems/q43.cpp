#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const int INF = 1001001001;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    int n;
    cin >> n;
    vector<string> s(5);
    rep(i,0,5) cin >> s[i];
    Matrix dp(n+1, vector<int>(3,INF));
    rep(j,0,3) dp[0][j] = 0;
    rep(i,0,n) {
        rep(j,0,3) {
            rep(k,0,3) {
                if (j == k) continue;
                int v = 0;
                rep(l,0,5) if ((k == 0 && s[l][i] != 'R') || (k == 1 && s[l][i] != 'B') || (k == 2 && s[l][i] != 'W')) v++;
                chmin(dp[i+1][k], dp[i][j] + v);
            }
        }
    }
    int ans = INF;
    rep(j,0,3) chmin(ans, dp[n][j]);
    cout << ans << endl;
    return 0;
}
