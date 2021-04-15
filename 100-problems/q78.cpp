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
    int m, n;
    cin >> m >> n;
    int k;
    cin >> k;
    vector<string> joi(m);
    rep(i,0,m) cin >> joi[i];
    Matrix target(k, vector<int>(4));
    rep(i,0,k) rep(j,0,4) cin >> target[i][j];
    Matrix j_cum(m+1, vector<int>(n+1, 0));
    Matrix o_cum(m+1, vector<int>(n+1, 0));
    Matrix i_cum(m+1, vector<int>(n+1, 0));
    rep(i,0,m) {
        rep(j,0,n) {
            int j_now = (joi[i][j] == 'J') ? 1 : 0;
            int o_now = (joi[i][j] == 'O') ? 1 : 0;
            int i_now = (joi[i][j] == 'I') ? 1 : 0;
            j_cum[i+1][j+1] = j_cum[i+1][j] + j_cum[i][j+1] - j_cum[i][j] + j_now;
            o_cum[i+1][j+1] = o_cum[i+1][j] + o_cum[i][j+1] - o_cum[i][j] + o_now;
            i_cum[i+1][j+1] = i_cum[i+1][j] + i_cum[i][j+1] - i_cum[i][j] + i_now;

        }
    }
    rep(i,0,k) {
        int r1 = target[i][0]; int c1 = target[i][1];
        int r2 = target[i][2]; int c2 = target[i][3];
        r1--; c1--;
        int ans_j = j_cum[r2][c2] - j_cum[r2][c1] - j_cum[r1][c2] + j_cum[r1][c1];
        int ans_o = o_cum[r2][c2] - o_cum[r2][c1] - o_cum[r1][c2] + o_cum[r1][c1];
        int ans_i = i_cum[r2][c2] - i_cum[r2][c1] - i_cum[r1][c2] + i_cum[r1][c1];
        cout << ans_j << ' ' << ans_o << ' ' << ans_i << endl;
    }
    return 0;
}
