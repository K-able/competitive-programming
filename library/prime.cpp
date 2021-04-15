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

template<class T> void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> void chmin(T& a, T b) { if (a > b) a = b; }

const ll MAX_N = 1e6;
int prime[MAX_N];
bool is_prime[MAX_N + 1];
bool is_prime_small[MAX_N + 1];

bool check_is_prime(int n) {
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return n != 1;
}

map<int, int> prime_factor(int n) {
    map<int, int> res;
    for (int i = 2; i*i <= n; ++i) {
        while (n % i == 0) {
            ++res[i];
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

int sieve(int n) {
    int p = 0;
    rep(i,0,n+1) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    rep(i,2,n+1) {
        if (is_prime[i]) {
            prime[p++] = i;
            for (int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return p;
}

void segment_sieve(ll a, ll b) {
    for (int i = 0; (ll)i * i < b; i++) is_prime_small[i] = true;
    rep(i,0,b-a) is_prime[i] = true;
    for (int i = 2; (ll)i * i < b; i++) {
        if (is_prime_small[i]) {
            for (int j = 2 * i; (ll)j * j < b; j += i) is_prime_small[j] = false;
            for (ll j = max(2LL, (a+i-1)/i) * i; j < b; j += i) is_prime[j-a] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;
    cout << n << ": prime? " << check_is_prime(n) << endl;
    return 0;
}
