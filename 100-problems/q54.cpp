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

template<class T> bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;    
    } else {
        return false;
    }
}

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i,0,n) cin >> c[i];
    vector<int> dp(n+1, INF);
    dp[0] = -1;
    rep(i,0,n) {
        int res = lower_bound(all(dp),c[i]+1) - dp.begin();
        dp[res] = c[i];
    }
    cout << n - (lower_bound(all(dp), INF) - dp.begin() - 1) << endl;
    return 0;
}
