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
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}

int main() {
    int n, k;
    cin >> n >> k;
    Matrix a(n, vector<int>(n));
    rep(i,0,n) rep(j,0,n) cin >> a[i][j];
    int L = k*k/2+1;
    
    int wa = -1, ac = 1001001001;
    while(wa+1 < ac) {
        int wj = (wa+ac) / 2;
        bool ok = false;
        Matrix s(n+1, vector<int>(n+1));
        rep(i,0,n) rep(j,0,n) s[i+1][j+1] = a[i][j] > wj ? 1 : 0;
        rep(i,0,n+1) rep(j,0,n) s[i][j+1] += s[i][j];
        rep(i,0,n) rep(j,0,n+1) s[i+1][j] += s[i][j];
        rep(i,0,n-k+1) rep(j,0,n-k+1) {
            int now = s[i+k][j+k];
            now -= s[i][j+k];
            now -= s[i+k][j];
            now += s[i][j];
            if (now < L) ok = true;
        }
        if (ok) ac = wj;
        else wa = wj;
    }
    cout << ac << endl;
    return 0;
}
