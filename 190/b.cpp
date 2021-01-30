#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, s, d;
    cin >> n >> s >> d;
    vector<P> xy(n);
    rep(i,n) {
        int x, y;
        cin >> x >> y;
        xy[i] = make_pair(x, y);
    }
    string ans = "No";
    rep(i,n) {
        int x = xy[i].first;
        int y = xy[i].second;
        if (x < s && y > d) {
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
