#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll mc = b / c - (a - 1) / c;
    ll md = b / d - (a - 1) / d;
    ll cd = c * d / __gcd(c,d);
    ll mcd = b / cd - (a - 1) / cd;
    cout << (b - a + 1) - (mc + md - mcd) << endl; 
    return 0;
}
