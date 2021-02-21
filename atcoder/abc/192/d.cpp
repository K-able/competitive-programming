#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    /* submission
    string x;
    ll m;
    cin >> x >> m;
    ll x_num = atol(x.c_str());
    string x_tmp = x;
    sort(all(x_tmp), greater<char>{});
    int d = (int)(x_tmp[0] - '0');
    int n = d + 1;
    int l = x.length();
    reverse(all(x));
    ll ans = 0;
    ll last = 0;
    while(true) {
        ll x_n = 0;
        ll p = 1;
        rep(i,0,l) {
            x_n += (ll)(x[i] - '0') * p;
            if (x_n > m || x_n < 0) break;
            p *= n;
        }
        cout << x_n << " " << last << endl;
        if (x_n - last == 1) {
            ans += (m - n +1);
            break;
        } else if (x_n == last) {
            break;
        }
        if (x_n <= m && x_n > 0) {
            ans++;
        } else {
            break;
        }
        n++;
        last = x_n;
    }
    cout << ans << endl;
    */
    // ans
    string x;
    ll m;
    cin >> x >> m;
    if (x.size() == 1) {
        if (stoi(x) <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
    int d = 0;
    for (char c : x) d = max(d, int(c-'0'));
    ll ok = d, ng = m+1;
    while (ng - ok > 1) {
        ll n = (ok + ng) / 2;
        ll v = 0;
        for (char c : x) {
            if (v > m / n) v = m + 1;
            else v = v*n + (c-'0');
        }
        if (v <= m) ok = n;
        else ng = n;
    }
    cout << ok - d << endl;
    return 0;
}
