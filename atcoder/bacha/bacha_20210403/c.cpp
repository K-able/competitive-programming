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
    vector<int> a(3);
    rep(i,0,3) cin >> a[i];
    int ans = 1e6;
    rep(i,0,3) {
        rep(j,0,3) {
            if (i == j) continue;
            rep(k,0,3) {
                if (i == k || j == k) continue;
                ans = min(ans, abs(a[i]-a[j]) + abs(a[j]-a[k]));
            }
        }
    }
    cout << ans << endl;
    return 0;
}
