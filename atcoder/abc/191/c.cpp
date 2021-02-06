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
    int ans = 0;
    rep(i,h-1) {
        rep(j,w-1) {
            int cnt = 0;
            if (s[i][j] == '#') cnt++;
            if (s[i+1][j] == '#') cnt++;
            if (s[i][j+1] == '#') cnt++;
            if (s[i+1][j+1] == '#') cnt++;
            if (cnt == 1 || cnt == 3) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
