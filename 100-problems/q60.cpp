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
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n, vector<ll>(n, INF));
    rep(e,0,m) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }
    rep(v,0,n) dp[v][v] = 0;
    rep(k,0,n) {
        rep(i,0,n) {
            rep(j,0,n) {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    bool exist_negative_cycle = false;
    rep(v,0,n) if (dp[v][v] < 0) exist_negative_cycle = true;
    if (exist_negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        rep(i,0,n) {
            rep(j,0,n) {
                if (j) cout << " ";
                if (dp[i][j] < INF/2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }
    return 0;
}
