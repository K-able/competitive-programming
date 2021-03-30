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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    ll ans = INF;
    rep(i,0,1<<(n-1)) {
        ll ans_i = 0;
        ll tmp = a[0];
        rep(j,0,n-1) {
            if ((i >> j) & 1) {
                ans_i ^= tmp;
                tmp = a[j+1];
            } else {
                tmp |= a[j+1];
            }
        }
        ans_i ^= tmp;
        ans = min(ans, ans_i);
    }
    cout << ans << endl;
    /*
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    ll ans = INF;
    rep(i,0,1<<(n-1)) {
        ll ans_i = 0;
        ll tmp = 0;
        rep(j,0,n) {
            tmp |= a[j];
            if (i >> j & 1) {
                ans_i ^= tmp;
                tmp = 0;
            }
        }
        ans_i ^= tmp;
        ans = min(ans, ans_i);
    }
    cout << ans << endl;
    */
    return 0;
}