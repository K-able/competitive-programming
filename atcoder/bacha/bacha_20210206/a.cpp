#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    string ans = "APPROVED";
    rep(i,n) {
        if (a[i] % 2 == 0 && a[i] % 3 != 0 && a[i] % 5 != 0) ans = "DENIED";
    }
    cout << ans << endl;
    return 0;
}
