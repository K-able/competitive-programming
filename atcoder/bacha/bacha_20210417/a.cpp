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
    int n, m;
    cin >> n >> m;
    Matrix b(n+2, vector<int>(m+2, 0));
    rep(i,1,n+1) {
        string s;
        cin >> s;
        rep(j,1,s.size()+1) b[i][j] = (int)(s[j-1] - '0');
    }
    Matrix ans(n+2, vector<int>(m+2, 0));
    rep(x,1,m+1) {
        rep(y,1,n+1) {
            if (b[y][x] == 0) continue;
            int now = b[y][x];
            ans[y][x+1] += now;
            rep(i,0,4) {
                int sy = y + dy[i];
                int sx = x + 1 + dx[i];
                b[sy][sx] -= now;
            }
        }
    }
    rep(i,1,n+1) {
        rep(j,1,m+1) cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
