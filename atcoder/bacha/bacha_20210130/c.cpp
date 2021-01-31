#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b;
    cin >> a >> b;
    int ans = -1;
    rep(i,1010){
        int i_a = floor(i * 0.08);
        int i_b = floor(i * 0.1);
        if (i_a == a && i_b == b) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
