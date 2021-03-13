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
    int n;
    cin >> n;
    vector<int> a(n);
    /* O(N+(max|Ai|^2))
    vector<int> cnt(401, 0);
    rep(i,0,n) {
        cin >> a[i];
        cnt[a[i]+200]++;
    }
    ll ans = 0;
    rep(i,0,400) {
        rep(j,i,401) {
            int i_adj = i - 200; int j_adj = j - 200;
            ans += pow(i_adj - j_adj, 2) * cnt[i] * cnt[j];
        }
    }
    cout << ans << endl;
    */
    // O(N)
    rep(i,0,n) cin >> a[i];
    vector<ll> s1(n+1, 0);
    vector<ll> s2(n+1, 0);
    rep(i,0,n) {
        s1[i+1] = s1[i] + a[i] * a[i];
        s2[i+1] = s2[i] + a[i];
    }
    ll ans = n * s1[n] - s2[n] * s2[n];
    cout << ans << endl;
    return 0;
}
