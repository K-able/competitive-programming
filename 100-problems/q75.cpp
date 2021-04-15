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
const int MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

struct mint {
    ll x;
    mint(ll x = 0) : x((x % MOD + MOD) % MOD){};
    mint operator-() const { return mint(-x); }
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) {
        mint res(*this);
        return res *= a;
    }
    mint pow(ll t) const { 
        if (!t) return 1;
        mint a = pow(t>>1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    // for prime mod
    mint inv() const {
        return pow(MOD - 2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
};

int n;
vector<int> to[200005];
mint ans;

int dfs(int v, int p = -1) {
    int res = 1;
    vector<int> ts;
    for (int u : to[v]) {
        if (u == p) continue;
        int t = dfs(u, v);
        res += t;
        ts.push_back(t);
    }
    if (p != -1) {
        ts.push_back(n - res);
    }
    mint now = mint(2).pow(n-1)-1;
    for (int t : ts) {
        now -= mint(2).pow(t)-1;
    }
    ans += now;
    return res;
}

int main() {
    cin >> n;
    rep(i,0,n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dfs(0);
    ans /= mint(2).pow(n);
    cout << ans.x << endl;
    return 0;
}
