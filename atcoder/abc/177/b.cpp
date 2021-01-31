#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string s, t;
    cin >> s >> t;
    int ans = 1e9;
    rep(si,s.size()) {
        if (si+t.size() > s.size()) break;
        int cnt = 0;
        rep(i,t.size()) {
            if (s[si+i] != t[i]) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
