#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int mod = 1'000'000'007;
    int n;
    cin >> n;

    ll tens = 1; ll nines = 1; ll eights = 1;
    rep(i,n) {
        tens = tens * 10 % mod;
        nines = nines * 9 % mod;
        eights = eights * 8 % mod;
    }
    int ans = (tens - nines + mod) % mod;
    ans = (ans - nines + mod) % mod;
    ans = (ans + eights) % mod;
    cout << ans << endl;

    return 0;
}
