#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));
    vector<ll> s(n);
    s[0] = a[0];
    for (int i = 1; i < n; ++i) s[i] = s[i-1] + a[i];
    
    int ans = 1;
    for (int i = n-2; i >= 0; --i) {
        if (s[i] * 2 >= a[i+1]) ans++;
        else break;
    }
    cout << ans << endl;

    return 0;
}
