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

vector<int> cumsum(const vector<int> a) {
    int n = a.size();
    vector<int> s(n+1, 0);
    rep(i,0,n) s[i+1] = s[i] + a[i];
    return s;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    vector<int> s = cumsum(a);
    rep(i,0,n+1) cout << s[i] << " ";
    cout << endl;
    return 0;
}
