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
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

ll modpow(ll a, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll modinv(ll a, ll mod) {
    return modpow(a, mod - 2, mod);
}

int main() {
    int x, y;
    cin >> x >> y;
    if ((x + y) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    int n = (x + y) / 3;
    int r = -1;
    // k -> num of (i+2, j+1), n-k -> num of (i+1, j+2)
    rep(k,0,n+1) {
        if (2 * k + (n - k) == x && k + 2 * (n - k) == y) r = k;
    }
    ll ans = 1;
    if (r == -1) {
        ans = 0;
    } else {
        rep(i,1,n+1) ans = (ans * i % MOD);
        rep(i,1,r+1) ans = (ans * modinv(i, MOD) % MOD);
        rep(i,1,n-r+1) ans = (ans * modinv(i, MOD) % MOD);
    }
    cout << ans << endl;
    return 0;
}
