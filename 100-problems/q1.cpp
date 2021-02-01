#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    vector<P> nx;
    while (true) {
        int n, x;
        cin >> n >> x;
        if (n == 0 && x == 0) break;
        nx.push_back(make_pair(n,x));
    }
    for (auto [n, x] : nx) {
        int ans = 0;
        for (int i = 1; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                int k = x - i - j;
                if (k > j && k <= n) ans++;
            }
        }
        cout << ans << endl;    
    }
    return 0;
}
