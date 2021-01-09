#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> p(n);
    rep(i,n){
        p[i] = l + i;
    }
    int skip = 0;
    int min = 1LL << 10;
    rep(i,n){
        if (abs(p[i]) < min) {
            min = abs(p[i]);
            skip = i;
        }
    }
    int ans = 0;
    rep(i,n){
        if (i == skip) continue;
        ans += p[i];
    }
    cout << ans << endl;
    return 0;
}
