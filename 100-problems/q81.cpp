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
    vector<int> x(1000001, 0);
    rep(i,0,n) {
        int a, b;
        cin >> a >> b;
        x[a]++;
        x[b+1]--;
    }
    int s = 0;
    int ans = 0;
    rep(i,0,1000001) {
        s += x[i];
        ans = max(ans, s);
    }
    cout << ans << endl;
    return 0;
}

