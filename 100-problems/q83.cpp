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
    ll n, m;
    cin >> n >> m;
    vector<ll> p(100005);
    rep(i,1,m+1) cin >> p[i];
    vector<ll> freq(100005, 0);
    rep(i,1,m) {
        if (p[i] < p[i+1]) {
            freq[p[i]]++;
            freq[p[i+1]]--;
        } else {
            freq[p[i+1]]++;
            freq[p[i]]--;
        }
    }
    ll ans = 0;
    rep(i,1,n) {
        freq[i] += freq[i-1];
        ll a, b, c;
        cin >> a >> b >> c;
        ans += min(a * freq[i], b * freq[i] + c);
    }
    cout << ans << endl;
    return 0;
}
