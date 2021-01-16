#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];

    int l, r;
    vector<int> sort_x(n);
    copy(x.begin(), x.end(), sort_x.begin());
    sort(sort_x.begin(), sort_x.end());
    l = sort_x[n/2-1];
    r = sort_x[n/2];

    rep(i,n){
        if (x[i] <= l) cout << r << endl;
        else cout << l << endl;
    }
    return 0;
}
