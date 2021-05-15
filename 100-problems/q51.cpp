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
const ll MOD = 1e4+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    int n;
    string s;
    cin >> n >> s;
    Matrix dp(n+10, vector<int>(1<<3+10, 0));
    map<char, int> m;
    m['J'] = 2; m['O'] = 1; m['I'] = 0;
    dp[0][1<<m['J']] = 1;
    rep(i,0,n) {
        char ch = s[i];
        rep(j,0,1<<3) {
            if (dp[i][j] == 0) continue;
            rep(l,0,1<<3) {
                vector<bool> attend(3, false);
                rep(x,0,3) if ((l>>x) & 1) attend[x] = true;
                if (!attend[m[ch]]) continue;
                if ((j & l) == 0) continue;
                dp[i+1][l] = (dp[i+1][l] + dp[i][j]) % MOD;
            }
        }
    }
    int ans = 0;
    rep(j,0,1<<3) ans = (ans + dp[n][j]) % MOD;
    cout << ans << endl;
    return 0;
}
