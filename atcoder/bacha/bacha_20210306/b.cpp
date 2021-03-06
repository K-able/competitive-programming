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

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = 1;
    if (abs(n-m)>1) {
        ans = 0;
    } else if (abs(n-m)==1) {
        rep(i,1,n+1) ans = ans * i % MOD;
        rep(i,1,m+1) ans = ans * i % MOD;
    } else {
        rep(i,1,n+1) {
            ans = ans * i % MOD;
            ans = ans * i % MOD;
        }
        ans = ans * 2 % MOD;
    }
    cout << ans << endl;
    return 0;
}
