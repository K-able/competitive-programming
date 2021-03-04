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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    int ans = 0;
    int count = 0;
    rep(i,1,n) {
        if (a[i-1] < a[i]) {
            count++;
        } else {
            if (count >= k-1) ans += count - k + 2;
            count = 0;
        }
    }
    if (count >= k-1) ans += count - k + 2;
    cout << ans << endl;

    return 0;
}
