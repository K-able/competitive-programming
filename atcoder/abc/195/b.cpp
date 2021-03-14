#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
using Matrix = vector<vector<int>>;

const int INF = 1e8;
const ld EPS = 1e-14;
const ll MOD = 1'000'000'007;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

int main() {
    // submit
    int a, b, w;
    cin >> a >> b >> w;
    w *= 1000;
    if (w % a != 0 && w - (w/a) * a > (b-a) * (w/a)) cout << "UNSATISFIABLE" << endl;
    else cout << w / b + (bool)(w % b) << " " << w / a << endl;
    /* late
    int l = INF, r = -INF;
    rep(i,1,w+1) {
        if (a*i <= w && w <= b*i) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    if (l == INF) cout << "UNSATISFIABLE" << endl;
    else cout << l << " " << r << endl;
    */
    return 0;

}
