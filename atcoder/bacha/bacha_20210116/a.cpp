#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    string N;
    cin >> N;
    int ans = 0;
    rep(i,4){
        if (N[i] == '2') ans += 1;
    }
    cout << ans << endl;
}
