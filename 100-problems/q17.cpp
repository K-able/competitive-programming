#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ld eps = 1e-14;

int main() {
    int k;
    cin >> k;
    vector<P> rc(k);
    rep(i,k) cin >> rc[i].first >> rc[i].second;
    vector<int> perm(8);
    rep(i,8) perm[i] = i;
    vector<string> ans(8, "........");

    do {
        bool flg = true;
        rep(i,k) {
            int r = rc[i].first; int c = rc[i].second;
            if (c != perm[r]) flg = false;
        }
        if (!flg) continue;
        rep(i,8) {
            int r = i; int c = perm[i];
            for (int j = 1; j < 8; ++j) {
                int dr = r + j; int dc = c + j;
                if (0 <= dr && dr <= 7 && 0 <= dc && dc <= 7 && dc == perm[dr]) flg = false;
                dr = r - j;
                if (0 <= dr && dr <= 7 && 0 <= dc && dc <= 7 && dc == perm[dr]) flg = false;
            }
        }
        if (flg) {
            rep(i,8) ans[i][perm[i]] = 'Q';
            break;   
        }
    } while (next_permutation(perm.begin(), perm.end()));
    rep(i,8) cout << ans[i] << endl;

    return 0;
}
