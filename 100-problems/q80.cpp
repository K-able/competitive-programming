#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<ll>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    int h, w; ll k, v;
    cin >> h >> w >> k >> v;
    Matrix a(h, vector<ll>(w));
    rep(i,0,h) rep(j,0,w) cin >> a[i][j];
    Matrix s(h+1, vector<ll>(w+1, 0));
    rep(i,0,h) rep(j,0,w) s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + a[i][j];
    int ans = 0;
    rep(h1,1,h+1) {
        rep(w1,1,w+1) {
            rep(h2,1,h+1) {
                rep(w2,1,w+1) {
                    int area = (h2 - h1 + 1) * (w2 - w1 + 1);
                    ll value = s[h2][w2] - s[h2][w1-1] - s[h1-1][w2] + s[h1-1][w1-1] + k * area;
                    if (value > v) continue;
                    ans = max(ans, area);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
