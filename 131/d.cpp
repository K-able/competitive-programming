#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> ba(n);    
    rep(i,n){
        ll a, b;
        cin >> a >> b;
        ba[i] = make_pair(b, a);
    }
    sort(ba.begin(), ba.end());
    
    ll day = 0;
    string ans = "Yes";
    rep(i,n){
        if (ba[i].first < day + ba[i].second) {
            ans = "No";
            break;
        }
        day += ba[i].second;
    }
    cout << ans << endl;
    return 0;
}
