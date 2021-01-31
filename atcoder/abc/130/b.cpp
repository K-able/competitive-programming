#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    rep(i,n) cin >> l[i];

    vector<int> s(n+1, 0);
    rep(i,n) s[i+1] = s[i] + l[i];
    cout << upper_bound(s.begin(), s.end(), x) - s.begin() << endl;

    return 0;
}
