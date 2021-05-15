#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const int INF = 1e9;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int h, w;
Matrix board;
bool visited[2010][2010];
int mem[2010][2010];

int f(int i, int j) {
    if (i == h-1 && j == w-1) return 0;
    if (visited[i][j]) return mem[i][j];
    visited[i][j] = true;
    int res = -INF;
    if (j+1 < w) res = max(res, board[i][j+1]-f(i,j+1));
    if (i+1 < h) res = max(res, board[i+1][j]-f(i+1,j));
    return mem[i][j] = res;
}

int main() {
    cin >> h >> w;
    board.assign(h, vector<int>(w));
    rep(i,0,h) {
        rep(j,0,w) {
            char c;
            cin >> c;
            if (c == '+') board[i][j] = 1;
            else if (c == '-') board[i][j] = -1;
        }
    }
    int score = f(0,0);
    if (score > 0) cout << "Takahashi" << endl;
    else if (score < 0) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}
