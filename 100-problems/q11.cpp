#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    rep(i,m) {
        int k;
        cin >> k;
        s[i].resize(k);
        rep(j,k) {
            cin >> s[i][j];
            --s[i][j];
        }
    }
    vector<int> p(m);
    rep(i,m) cin >> p[i];

    int ans = 0;
    rep(i,1<<n) {
        bool success = true;
        rep(j,m) {
            int sum = 0;
            for (int k : s[j]) {
                if ((i >> k) & 1) ++sum;
            }
            if (sum % 2 != p[j]) {
                success = false;
                break;
            }
        }
        if (success) ++ans;
    }
    cout << ans << endl;

    return 0;
}
