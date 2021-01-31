#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b;
    cin >> a >> b;
    int ans = -1;
    long double x = ((a + b) / 2.0);
    if (x == floor(x)) ans = floor(x);
    if (ans == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;
    return 0;
}
