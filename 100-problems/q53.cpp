#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const int INF = 100100100;
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
    vector<int> dp(n+10, INF);
    /* O(n^2)
    rep(j,0,n) {
        rep(i,0,n) {
            if (i == 0) chmin(dp[i], a[j]);
            else if (dp[i-1] < a[j]) chmin(dp[i], a[j]);
        }
    }
    */
    // O(nlogn)
    rep(i,0,n) *lower_bound(all(dp), a[i]) = a[i];
    cout << lower_bound(all(dp), INF) - dp.begin() << endl;
    return 0;
}
