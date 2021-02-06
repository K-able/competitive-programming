#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int f_cnt = 0;
    int s_cnt = 0;
    if (a == 5) f_cnt++;
    else if (a == 7) s_cnt++;
    if (b == 5) f_cnt++;
    else if (b == 7) s_cnt++;
    if (c == 5) f_cnt++;
    else if (c == 7) s_cnt++;
    string ans = "NO";
    if (f_cnt == 2 && s_cnt == 1) ans = "YES";
    cout << ans << endl;
    
    return 0;
}
