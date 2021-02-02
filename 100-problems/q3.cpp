#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
    string s;
    cin >> s;
    int ans = 0;
    rep(i,s.size()) {
        int cnt = 0;
        if (s[i] != 'A' && s[i] != 'G' && s[i] != 'C' && s[i] != 'T') continue;
        cnt++;
        for (int j = i+1; j < s.size(); ++j) {
            if (s[j] != 'A' && s[j] != 'G' && s[j] != 'C' && s[j] != 'T') break;
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}
