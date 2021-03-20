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
const ll MOD = 1'000'000'007;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int h, w, a, b;
bool used[16][16];

int dfs(int i, int j, int a, int b) {
    if (a < 0 || b < 0) return 0;
    if (j == w) return dfs(i+1, 0, a, b);
    if (i == h) return 1;
    if (used[i][j]) return dfs(i, j+1, a, b);
    int res = 0;
    used[i][j] = true;
    res += dfs(i, j+1, a, b-1);
    if (j+1 < w && !used[i][j+1]) {
        used[i][j+1] = true;
        res += dfs(i, j+1, a-1, b);
        used[i][j+1] = false;
    }
    if (i+1 < h && !used[i+1][j]) {
        used[i+1][j] = true;
        res += dfs(i, j+1, a-1, b);
        used[i+1][j] = false;
    }
    used[i][j] = false;
    return res;
}

int main() {    
    cin >> h >> w >> a >> b;
    cout << dfs(0,0,a,b) << endl;
    return 0;
}
