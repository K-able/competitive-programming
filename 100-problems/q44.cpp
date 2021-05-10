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
    vector<int> dp(2001001, INF);
    vector<int> dp_odd(2001001, INF);
    rep(i,1,200) {
        int x = i * (i+1) * (i+2) / 6;
        dp[x] = 1;
        if (x % 2 != 0) dp_odd[x] = 1;
    }
    for (int i = 200; i > 0; --i) {
        int x = i * (i+1) * (i+2) / 6;
        rep(j,x+1,1001001) {
            chmin(dp[j], dp[x] + dp[j-x]);
            chmin(dp_odd[j], dp_odd[x] + dp_odd[j-x]);
        }
    }
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        cout << dp[n] << " " << dp_odd[n] << endl;
    }
    return 0;
}
