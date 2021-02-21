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
    int n, va, vb, l;
    cin >> n >> va >> vb >> l;
    ld next_dist = l;
    rep(i,n) {
        ld a_sec = next_dist / va;
        next_dist = a_sec * vb;
    }
    cout << fixed << setprecision(10) << next_dist << endl;
    return 0;
}
