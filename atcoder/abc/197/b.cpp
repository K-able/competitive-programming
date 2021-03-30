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
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vector<vector<char>> s(h, vector<char>(w));
    rep(i,0,h) rep(j,0,w) cin >> s[i][j];
    int ans = 1;
    rep(i,1,h) {
        if (x+i >= h || s[x+i][y] == '#') break;
        ans++;
    }
    rep(i,1,h) {
        if (x-i < 0 || s[x-i][y] == '#') break;
        ans++;
    }
    rep(i,1,w) {
        if (y+i >= w || s[x][y+i] == '#') break;
        ans++;
    }
    rep(i,1,w) {
        if (y-i < 0 || s[x][y-i] == '#') break;
        ans++;
    }
    cout << ans << endl;
    /*
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--; y--;
    vector<string> s(h);
    rep(i,0,h) cin >> s[i];
    int ans = 0;
    rep(v,0,4) {
        int ni = x, nj = y;
        while(true) {
            ni += dx[v];
            nj += dy[v];
            if (ni < 0 || nj < 0 || ni >= h || nj >= w) break;
            if (s[ni][nj] == '#') break;
            ++ans;
        }
    }
    cout << ans << endl;
    */
    return 0;
}
