#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int ans = 1LL << 30;
    for (int i = 0; i < 200001; ++i) {
        int xr = max(0, x - (int)(i / 2));
        int yr = max(0, y - (int)(i / 2));
        ans = min(ans, a * xr + b * yr + c * i);
        if (xr == 0 && yr == 0) break;
    }
    cout << ans << endl;
    return 0;
}
