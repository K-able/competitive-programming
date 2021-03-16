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

void sieve(vector<bool> &is_prime, int n) {
    is_prime[0] = is_prime[1] = false;
    rep(i,2,n+1) {
        if (is_prime[i]) {
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

int main() {
    int q;
    cin >> q;
    vector<bool> is_prime(1e5+1, true);
    sieve(is_prime, 1e5);
    vector<bool> is_prime2(1e5+1, false);
    rep(n,0,1e5) {
        if (n % 2 == 0) continue;
        if (is_prime[n] && is_prime[(n+1)/2]) is_prime2[n] = true;
    }
    vector<int> sum_prime(1e5+2, 0);
    rep(i,0,1e5) sum_prime[i+1] = sum_prime[i] + is_prime2[i];
    rep(i,0,q) {
        int l, r;
        cin >> l >> r;    
        int ans = sum_prime[r+1] - sum_prime[l];
        cout << ans << endl;
    }
    return 0;
}
