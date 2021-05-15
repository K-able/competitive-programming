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
    string s;
    cin >> s;
    int ans = 0;
    rep(i,0,10000) {
        ostringstream sout;
        sout << std::setfill('0') << std::setw(4);    
        sout << i;
        string si = sout.str();
        vector<bool> check(10, false);
        rep(j,0,4) check[int(si[j]-'0')] = true;
        //int x = i;
        /*rep(j,0,4) {
            int d = x % 10;
            check[d] = true;
            x /= 10;
        }*/
        bool ok = true;
        rep(j,0,10) {
            if (s[j] == 'o' && check[j] == false) ok = false;
            if (s[j] == 'x' && check[j] == true) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}
