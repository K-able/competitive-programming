#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int r = 0, w = 0;
    rep(i,n) if (s[i] == 'R') ++r;
    int ans = max(r,w);
    rep(i,n) {
        if (s[i] == 'R') --r;
        else ++w;
        int now = max(r,w);
        ans = min(ans,now);
    }
    cout << ans << endl;
    return 0;
}
