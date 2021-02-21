#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
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

int main() {
    int n, k;
    cin >> n >> k;
    string ans = "";
    if (n % 2 == 0) ans = (n / 2 >= k) ? "YES" : "NO";
    else ans = (n / 2 + 1 >= k) ? "YES" : "NO";
    cout << ans << endl;
}
