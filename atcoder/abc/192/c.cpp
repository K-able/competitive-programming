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
    ll n, k;
    cin >> n >> k;
    string ans = to_string(n);
    rep(i,0,k) {
        string x = ans;
        sort(all(x), greater<char>{});
        ll g1 = atoi(x.c_str());
        sort(all(x));
        ll g2 = atoi(x.c_str());
        ans = to_string(g1 - g2);
    }
    cout << ans << endl;
    return 0;
}
