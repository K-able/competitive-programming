#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    while (n > 0) {
        int origin = n;
        int nine = 9;
        int six = 6;
        while (n >= nine*9) {
            nine *= 9;
        }
        while (n >= six*6) {
            six *= 6;
        }
        if (n < 6) {
            ans += n;
            break;
        } else if (n < 9) {
            ans += 1;
            n -= 6;
        } else {
            n -= max(nine, six);
            ans += 1;
        }
        cout << origin - n << endl;
    }
    cout << ans << endl;
    return 0;
}
