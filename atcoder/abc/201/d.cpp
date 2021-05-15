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
Matrix mem;

int judge(int i, int j, int s1, int s2) {
    if (i == h-1 && j == w-1) {
        if (s1 > s2) return mem[i][j] = 1;
        else if (s1 < s2) return mem[i][j] = -1;
        else return mem[i][j] = 0;
    }
    if (mem[i][j] != INF) return mem[i][j];
    int result_h = -1;
    int result_w = -1;
    if (i+1 <= h-1) {
        s1 += board[i+1][j];
        int res = judge(i+1, j, s2, s1);
        if (res == -1) result_h = 1;
        else if (res == 0) result_h = 0;
        s1 -= board[i+1][j];
    }
    if (j+1 <= w-1) {
        s1 += board[i][j+1];
        int res = judge(i, j+1, s2, s1);
        if (res == -1) result_w = 1;
        else if (res == 0) result_w = 0;
        s1 -= board[i][j+1];
    }
    return mem[i][j] = max(result_h, result_w);
}

int main() {
    cin >> h >> w;
    board.assign(h, vector<int>(w));
    mem.assign(h, vector<int>(w, INF));
    rep(i,0,h) {
        rep(j,0,w) {
            char c;
            cin >> c;
            if (c == '+') board[i][j] = 1;
            else if (c == '-') board[i][j] = -1;
        }
    }
    int ans = judge(0, 0, 0, 0);
    if (ans == 1) cout << "Takahashi" << endl;
    else if (ans == -1) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
    return 0;
}
