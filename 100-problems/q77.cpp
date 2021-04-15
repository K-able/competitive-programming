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
const ll MOD = 1e5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

vector<int> cumsum(const vector<int> a) {
    int n = a.size();
    vector<int> s(n+1, 0);
    rep(i,0,n) s[i+1] = s[i] + a[i];
    return s;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> d(n-1);
    rep(i,0,n-1) cin >> d[i];
    vector<int> a(m, 0);
    rep(i,0,m) cin >> a[i];
    vector<int> s = cumsum(d);
    int ans = 0;
    int prev = 0;
    rep(i,0,m) {
        int now = prev + a[i];
        ans = (ans + (abs(s[now] - s[prev]))) % MOD;
        prev = now;
    }
    cout << ans << endl;
    return 0;
}
