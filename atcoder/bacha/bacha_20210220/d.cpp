#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> s_tmp(n);
    ll ans = 0;
    rep(i,1<<n-1) {
        int last = 0;
        rep(j,n-1) {
            if ((j == n-2) || ((i >> j) & 1)) {
                cout << s.substr(last, j) << endl;
                s_tmp.push_back(s.substr(last, j));
                last = j;
            }
        }
        rep(i,n) cout << s_tmp[i].c_str() << " " << atoi(s_tmp[i].c_str()) << endl;
    }
    cout << ans << endl;
    return 0;
}
