#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}

int main() {
    int n, w;
    cin >> n >> w;
    vector<int> value(n);
    vector<int> weight(n);
    rep(i,0,n) cin >> value[i] >> weight[i];
    vector<int> dp(w+1, 0);
    rep(i,0,n) {
        rep(j,0,w+1) {
            if (j + weight[i] <= w) chmax(dp[j+weight[i]], dp[j] + value[i]);
        }
    }
    cout << dp[w] << endl;

    return 0;
}
