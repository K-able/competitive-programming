#include <bits/stdc++.h>
#define rep(i,s,n) for (ll i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
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
    ll n, k;
    cin >> n >> k;
    vector<P> ab(n);
    rep(i,0,n) cin >> ab[i].first >> ab[i].second;
    sort(all(ab));
    ll now = k;
    rep(i,0,n) {
        ll a = ab[i].first;
        ll b = ab[i].second;
        if (now < a) break;
        now += b;
    }
    cout << now << endl;
    return 0;
}
