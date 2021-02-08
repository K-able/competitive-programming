#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;


int main() {
    int n;
    cin >> n;
    vector<P> xy(n);
    vector<int> perm(n);
    rep(i,n) {
        cin >> xy[i].first >> xy[i].second;
        perm[i] = i;
    }
    ld ans = 0;
    int cnt = 0;
    do {
        cnt++;
        rep(i,n-1) {
            ld d = sqrtl((xy[perm[i]].first - xy[perm[i+1]].first) * (xy[perm[i]].first - xy[perm[i+1]].first) + (xy[perm[i]].second - xy[perm[i+1]].second) * (xy[perm[i]].second - xy[perm[i+1]].second));
            ans += d;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    ans /= cnt;
    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}
