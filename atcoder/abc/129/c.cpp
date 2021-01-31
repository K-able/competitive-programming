#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll mod = 1'000'000'007;
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    
    vector<bool> can_use(n+1, true);
    for (int i = 1; i < n+1; ++i) {
        can_use[i] = (find(a.begin(),a.end(),i) == a.end()) ? true : false;
    }
    vector<ll> ans(n+1, 0);
    ans[0] = 1;
    rep(i,n) {
        if (can_use[i] == false) continue;
        if (can_use[i+1] == true) ans[i+1] = (ans[i+1] + ans[i]) % mod;
        if (i < n-1 && can_use[i+2] == true) ans[i+2] = (ans[i+2] + ans[i]) % mod; 
    }
    cout << ans[n] << endl;
    
    return 0;
}
