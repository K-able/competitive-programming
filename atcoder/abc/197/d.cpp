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

using C = complex<double>;
C inC() {
    double x, y;
    cin >> x >> y;
    return C(x,y);
}
int main() {
    /*
    int n, x0, y0, xn2, yn2;
    cin >> n >> x0 >> y0 >> xn2 >> yn2;
    ld theta = (180.0 / (ld)n) * M_PI / 180.0;
    ld a = sqrtl((x0 - xn2) * (x0 - xn2) + (y0 - yn2) * (y0 - yn2));
    ld b = a * cosl(theta);
    ld c = a * sinl(theta);
    */
    int n;
    cin >> n;
    C s = inC();
    C t = inC();
    C o = (s + t) / 2.0;
    double rad = 2 * M_PI / n;
    C r(cos(rad), sin(rad));
    C ans = o + (s - o) * r;
    cout << fixed << setprecision(10);
    cout << ans.real() << " " << ans.imag() << endl;
    return 0;
}
