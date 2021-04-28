#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int conv_s_to_i(string s) {
    if (s[0] == '0') return (int)(s[1] - '0');
    else return (int)(s[0] - '0') * 10 + (int)(s[1] - '0');
}

int conv_sh_to_ih(string s) {
    int res;
    int hh = conv_s_to_i(s.substr(0,2));
    int mm = conv_s_to_i(s.substr(3,2));
    int ss = conv_s_to_i(s.substr(6,2));
    if (hh == 0) {
        if (mm == 0) return ss;
        else return mm * 100 + ss;
    } else {
        return hh * 10000 + mm * 100 + ss;
    }
}

int main() {
    vector<int> ans;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vector<int> table(240000, 0);
        rep(i,0,n) {
            string sh, th;
            cin >> sh >> th;
            int si = conv_sh_to_ih(sh);
            int ti = conv_sh_to_ih(th);
            table[si]++; table[ti]--;            
        }
        int s = 0;
        int res = 0;
        rep(i,0,240000) {
            s += table[i];
            res = max(res, s);
        }
        ans.push_back(res);
    }
    rep(i,0,ans.size()) cout << ans[i] << endl;
    return 0;
}
