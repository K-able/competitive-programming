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

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    int t2_count = 0;
    // int fl = 0;
    rep(i,0,q) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            a--; b--;
            if (t2_count % 2 != 0) {
                if (a < n) a += n;
                else a -= n;
                if (b < n) b += n;
                else b -= n;
                // a = (a + n) % (2 * n)
                // b = (b + n) % (2 * n)
            }
            char c_a = s[a]; char c_b = s[b];
            s[a] = c_b; s[b] = c_a;
            // swap(s[a], s[b]);
        } else if (t == 2) {
            t2_count++;
            // flg ^= 1;
        }
    }
    if (t2_count % 2 != 0) {
        string s_a = s.substr(0,n);
        string s_b = s.substr(n);
        s = s_b + s_a;
    }
    cout << s << endl;
    return 0;
}
