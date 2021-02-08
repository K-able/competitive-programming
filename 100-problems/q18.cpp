#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ld eps = 1e-14;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    int q;
    cin >> q;
    vector<int> t(q);
    rep(i,q) cin >> t[i];
    
    int ans = 0;
    rep(i,q) {
        if (lower_bound(s.begin(), s.end(), t[i]) != s.end()) ans++;
    }
    cout << ans << endl;
    
    return 0;
}
