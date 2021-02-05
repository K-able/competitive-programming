#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    rep(i,r) rep(j,c) cin >> a[i][j];
    int ans = 0;
    rep(i,1<<r) {
        vector<vector<int>> b(r, vector<int>(c));
        copy(a.begin(), a.end(), b.begin());
        rep(j,r) {
            if ((i >> j) & 1) {
                rep(k, b[j].size()) b[j][k] ^= 1; 
            }
        }
        int same_cnt = 0;
        int other_cnt = 0;
        rep(j,c) {
            int cnt = 0;
            rep(k,r) cnt += b[k][j];
            if (cnt == 0 || cnt == r) same_cnt++;
            else other_cnt += cnt;
        }
        ans = max(ans, same_cnt * r + other_cnt);
    }
    cout << ans << endl;

    return 0;
}
