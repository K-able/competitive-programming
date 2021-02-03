#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    rep(i,1000) {
        int a[3] = {i / 100, (i / 10) % 10, i % 10};
        int cnt = 0;
        rep(j,n) {
            if (cnt <= 2 && a[cnt] == (int)(s[j]-'0')) cnt++;
        }
        if (cnt == 3) ans++;
    }
    cout << ans << endl;

    return 0;
}
