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
    int n;
    cin >> n;
    int m = 5;
    Matrix a(n, vector<int>(m));
    rep(i,0,n) rep(j,0,m) cin >> a[i][j];
    int ac = 0, wa = 1001001001;
    while (ac+1 < wa) {
        int wj = (ac + wa) / 2;
        vector<int> s;
        rep(i,0,n) {
            int x = 0;
            rep(j,0,m) {
                if (a[i][j] >= wj) x |= 1<<j;
            }
            s.push_back(x);
        }
        sort(all(s));
        s.erase(unique(all(s)), s.end());
        bool ok = false;
        rep(i,0,s.size()) rep(j,0,i+1) rep(k,0,j+1) {
            if ((s[i]|s[j]|s[k]) == (1<<m)-1) ok = true;
        }
        if (ok) ac = wj; else wa = wj;
    }
    cout << ac << endl;
    return 0;
}
