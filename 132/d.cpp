#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int mod = 1000000007;
struct mint {
    ll x;
    mint(ll x=0):x(x%mod){}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
};

mint c[4005][4005];
void init()  {
    c[0][0] = 1;
    rep(i,4000) {
        rep(j,4000) {
            c[i+1][j] += c[i][j];
            c[i+1][j+1] += c[i][j];
        }
    }
}
mint comb(int n, int k) {
    return c[n][k];
}
mint f2(int n, int k) {
    return comb(n+k-1, k-1);
}
mint f(int n, int k) {
    if (n < k) return 0;
    if (n == 0 && k == 0) return 1;
    return f2(n-k, k);
}

int main() {
    init();
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        mint blue = f(k, i);
        mint red = 0;
        {
            red += f(n-k, i-1);
            red += f(n-k, i);
            red += f(n-k, i);
            red += f(n-k, i+1);
        }
        mint ans = blue*red;
        printf("%lld\n", ans.x);
    }
    return 0;
}
