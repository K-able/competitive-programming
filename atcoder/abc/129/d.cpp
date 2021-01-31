#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> cnt(h, vector<int>(w));
    rep(i,h) {
        vector<int> done(w);
        rep(j,w) {
            if (s[i][j] == '#') continue;
            if (done[j]) continue;
            int l = 0;
            while (j+l < w) {
                if (s[i][j+l] == '#') break;
                ++l;
            }
            rep(k,l) {
                cnt[i][j+k] += l;
                done[j+k] = 1;
            }
        }
    }
    rep(j,w) {
        vector<int> done(h);
        rep(i,h) {
            if (s[i][j] == '#') continue;
            if (done[i]) continue;
            int l = 0;
            while (i+l < h) {
                if (s[i+l][j] == '#') break;
                ++l;
            }
            rep(k,l) {
                cnt[i+k][j] += l;
                done[i+k] = 1;
            }
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) ans = max(ans, cnt[i][j]-1);
    cout << ans << endl;

    return 0;
}
