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

int main() {
    // submit
    ll n;
    cin >> n;
    int k = to_string(n).size();
    ll ans = 0;
    rep(i,2,k+1) {
        int comma = (i-1) / 3;
        if (i != k) ans += (9 * pow(10, i-1)) * comma;
        else ans += (n - pow(10, i-1) + 1) * comma;
    }
    cout << ans << endl;
    /* late
    ll x = 1000;
    ll ans = 0;
    while (n >= x) {
        ans += n - x + 1;
        x *= 1000;
    }
    cout << ans << endl;
    */
    return 0;
}
