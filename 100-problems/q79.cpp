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
    int n, m, q;
    cin >> n >> m >> q;
    Matrix lr(n, vector<int>(n, 0));
    rep(i,0,m) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        lr[l][r]++;
    }
    Matrix s(n+1, vector<int>(n+1, 0));
    rep(l,0,n) {
        rep(r,0,n) {
            s[l+1][r+1] = s[l+1][r] + s[l][r+1] - s[l][r] + lr[l][r];
        }
    }
    vector<int> ans(q);
    rep(i,0,q) {
        int pi, qi;
        cin >> pi >> qi;
        pi--;
        ans[i] = s[qi][qi] - s[pi][qi] - s[qi][pi] + s[pi][pi];
    }
    rep(i,0,q) cout << ans[i] << endl; 
    return 0;
}
