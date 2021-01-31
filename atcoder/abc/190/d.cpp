#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll n;
    cin >> n;
    int ans = 0;
    vector<ll> divisor;
    for(ll i = 1; i * i <= 2*n; ++i) {
        if (2*n % i == 0) {
            divisor.push_back(i);
            if (i != 2*n / i) divisor.push_back(2*n / i);
        }
    }
    for (auto i : divisor) {
        if ((2*n/i-i+1) % 2 == 0) ans++;
    }
    cout << ans << endl;

    return 0;
}
