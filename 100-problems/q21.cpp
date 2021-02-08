#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n), s(n);
    rep(i,n) cin >> h[i] >> s[i];

    ll left = 0;
    ll right = INF;
    while (right - left > 1) {
        ll mid = (right + left) / 2;
        bool ok = true;
        vector<ll> target(n);
        rep(i,n) {
            if (mid < h[i]) ok = false;
            else target[i] = (mid - h[i]) / s[i];
        }
        sort(target.begin(), target.end());
        rep(i,n) {
            if (target[i] < i) {
                ok = false;
                break;
            }
        }
        if (ok) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}
