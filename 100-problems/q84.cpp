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
    Matrix sum(5010, vector<int>(5010, 0));
    rep(i,0,m) {
        int a, b, x;
        cin >> a >> b >> x;
        sum[a][b]++; sum[a+x+1][b+x+2]++; sum[a+x+2][b+1]++;
        sum[a][b+1]--; sum[a+x+1][b]--; sum[a+x+2][b+x+2]--;
    }
    rep(i,0,n+2) rep(j,0,n+2) sum[i][j+1] += sum[i][j];
    rep(i,0,n+2) rep(j,0,n+2) sum[i+1][j] += sum[i][j];
    rep(i,0,n+2) rep(j,0,n+2) sum[i+1][j+1] += sum[i][j];
    ll ans = 0;
    rep(i,0,n+1) rep(j,0,n+1) if (sum[i][j] >= 1) ans++;
    cout << ans << endl;

    return 0;
}
