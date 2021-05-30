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
    int n;
    cin >> n;
    vector<int> table(n);
    rep(i,0,n) {
        int s;
        cin >> s;
        table[i] = s;
        if (i % 2 == 0) continue;
        for (int j = i - 1; j >= 0 && table[j] != s; --j) {
            table[j] = s;
        }
    }
    int ans = count(all(table), 0);
    cout << ans << endl;
    return 0;
}
