#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) {
        if (a[i] != x) cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
