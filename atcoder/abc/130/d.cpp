#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    ll s = 0;
    int j = 0;
    ll ans = 0;
    rep(i,n){
        while(j < n && s+a[j] < k) {
            s += a[j];
            ++j;
        }
        ans += j-i;
        s -= a[i];
    }
    ans = (ll)n*(n+1)/2 - ans;
    cout << ans << endl;
    return 0;
}
