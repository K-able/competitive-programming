#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int right = 0;
    rep(i,n) {
        cin >> w[i];
        right += w[i];
    }
    int left = 0;
    int ans = 1 << 10;
    rep(i,n) {
        left += w[i];
        right -= w[i];
        ans = min(ans, abs(left-right));
    }
    cout << ans << endl;

    return 0;
}
