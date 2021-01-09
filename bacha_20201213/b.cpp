#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a[4];
    rep(i,4) cin >> a[i];
    string ans = "No";
    rep(i,1<<4) {
        int bit[10], x=0, y=0;
        rep(j,4) {
            int div = (1<<j);
            bit[j] = (i/div) % 2;
        }
        rep(j,4) {
            x += a[j] * bit[j];
            y += a[j] * ~bit[j];
        }
        if (x==y) {
            ans = "Yes";
            break;
        } 
    }
    cout << ans << endl;

    return 0;
}
