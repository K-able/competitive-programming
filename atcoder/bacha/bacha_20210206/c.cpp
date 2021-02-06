#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(), l.end());
    int ans = 0;
    rep(i,n-2) {
        int a = l[i];
        for (int j = i+1; j < n-1; ++j) {
            int b = l[j];
            int s = a + b - 1;
            //cout << a << " " << b << " " << s << endl;
            int search = upper_bound(l.begin(), l.end(), s) - l.begin();
            //cout << i << " " << j << " " << search << endl;
            //if (search == n) continue;
            ans += (search - (j + 1));
        }
    }
    cout << ans << endl;

    return 0;
}
