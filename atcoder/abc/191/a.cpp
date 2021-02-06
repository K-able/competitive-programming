#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int v, t, s, d;
    cin >> v >> t >> s >> d;
    if (d >= t * v && d <= s * v) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
