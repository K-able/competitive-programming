#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<P> ab(m);
    rep(i,m) {
        int a, b;
        cin >> a >> b;
        ab[i] = make_pair(a,b);
    }
    int k;
    cin >> k;
    vector<P> cd(k);
    rep(i,k) {
        int c, d;
        cin >> c >> d;
        cd[i] = make_pair(c,d);
    }
    int ans = -1;
    rep(i,2<<k+1) {
        int bit[k];
        vector<bool> used(n+1, false);
        rep(j,k) {
            int div = (1 << j);
            bit[j] = (i / div) % 2;   
        }
        rep(j,k) {
            if (bit[j] == 1) used[cd[j].first] = true;
            else used[cd[j].second] = true;
        }
        int cnt = 0;
        rep(j,m) {
            if (used[ab[j].first] == true && used[ab[j].second] == true) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
