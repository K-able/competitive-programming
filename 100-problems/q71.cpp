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

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    vector<ll> c(q+2,0);
    rep(i,1,q+1) {
        cin >> c[i];        
        c[i]--;
    }
    vector<ll> pass(n);
    rep(i,1,n) pass[i-1] = modpow(a[i-1], a[i], MOD);
    vector<ll> s(n, 0);
    rep(i,0,n-1) s[i+1] = (s[i] + pass[i]) % MOD;
    ll ans = 0;
    rep(i,0,q+1) {
        ll x = c[i];
        ll y = c[i+1];
        if (x > y) swap(x, y);
        ans = (ans + s[y] - s[x] + MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}