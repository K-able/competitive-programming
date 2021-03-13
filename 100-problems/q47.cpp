#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<ll>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
const ll MOD = 1'000'000'007;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int n; vector<ll> a; Matrix dp;

ll res(int l, int r, int t) {
    if (l > r) return 0;
    if (dp[l][r]) return dp[l][r];
    if (t) return dp[l][r] = max(res(l+1, r, 0) + a[l], res(l, r-1, 0) + a[r]);
    else return dp[l][r] = (a[l] > a[r]) ? res(l+1, r, 1) : res(l, r-1, 1);
}

int main() {
    // int s = clock();
    cin >> n; 
    a.assign(2*n, 0);
    dp.assign(2*n+1, vector<ll>(2*n+1,0));
    rep(i,0,n) {
        cin >> a[i];
        a[n+i] = a[i];
    }
    ll ans = 0;
    rep(i,0,n) chmax(ans, res(i, i+n-1, 1));
    cout << ans << endl;
    // int e = clock();
    // cout << (e - s) / CLOCKS_PER_SEC << endl;
    return 0;
}
