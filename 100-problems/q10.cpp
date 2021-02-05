#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int q;
    cin >> q;
    vector<int> m(q);
    rep(i,q) cin >> m[i];
    rep(i,q) {
        int mi = m[i];
        string ans = "no";
        rep(j,1<<n) {
            int s = 0;
            rep(k,n) {
                if ((j >> k) & 1 == 1) s += a[k];
            }
            if (s == mi) {
                ans = "yes";
                break;
            }
        }    
        cout << ans << endl;
    }    
    return 0;
}
