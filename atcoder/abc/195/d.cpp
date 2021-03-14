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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> w(n), v(n);
    rep(i,0,n) cin >> w[i] >> v[i];
    vector<int> x(m);
    rep(i,0,m) cin >> x[i];
    rep(i,0,q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        vector<int> as;
        rep(j,0,m) if (j < l || j > r) as.push_back(x[j]);
        sort(all(as));
        vector<bool> used(n);
        int ans = 0;
        for (int a : as) {
            P best(-1, -1);
            rep(k,0,n) {
                if (used[k]) continue;
                if (w[k] > a) continue;
                best = max(best, P(v[k], k));
            }
            int ii = best.second;
            if (ii == -1) continue;
            used[ii] = true;
            ans += v[ii];
        }
        cout << ans << endl;
    }
    return 0;
}
