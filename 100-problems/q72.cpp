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
const ll MOD = 1'000'000'007;
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
    int w, h;
    cin >> w >> h;
    ll n = w + h - 2;
    ll r = w - 1;
    ll ans = 1;
    for (ll i = n; i >= 1; --i) ans = ans * i % MOD;
    for (ll i = r; i >= 1; --i) ans = ans * modinv(i, MOD) % MOD;
    for (ll i = n - r; i >= 1; --i) ans = ans * modinv(i, MOD) % MOD;
    cout << ans << endl;
    return 0;
}
