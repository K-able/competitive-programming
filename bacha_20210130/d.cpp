#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    int ans = 0;
    int a = 0; int b = 0; int c = 0; int ab = 0;
    rep(i,n) {
        string si = s[i];
        if (si[si.size()-1] == 'A' && si[0] == 'B') {
            ab++;
        } else if (si[si.size()-1] == 'A') {
            a++;
        } else if (si[0] == 'B') {
            b++;
        }
        rep(j,si.size()-1) {
            if (si[j] == 'A' && si[j+1] == 'B') c++;
        }
    }
    ans += c;
    if (ab == 0) {
        ans += min(a,b); 
    } else {
        if (a + b == 0) {
            ans += min(a,b);
            ans += ab - 1;
        } else {
            ans += min(a,b);
            ans += ab;
        }
    }
    cout << ans << endl;

    return 0;
}
