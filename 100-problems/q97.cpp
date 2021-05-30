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

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}

int f(int x) {
    int res = 0;
    while (x % 2 == 0) {
        x /= 2;
        res++;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,0,n) {
        cin >> a[i];
        a[i] /= 2;
    }
    int t = f(a[0]);
    rep(i,0,n) {
        if (f(a[i]) != t) {
            cout << 0 << endl;
            return 0;
        }
        a[i] >>= t; // a[i] /= 2^t
    }
    m >>= t;
    ll l = 1;
    rep(i,0,n) {
        l = lcm(l, a[i]);
        if (l > m) {
            cout << 0 << endl;
            return 0;
        }
    }

    m /= l;
    int ans = (m + 1) / 2;
    cout << ans << endl;
    return 0;
}
