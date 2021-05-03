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
    int r = 0;
    string t = "";
    rep(i,0,s.size()) {
        if (s[i] == 'R') {
            r ^= 1;
        } else {
            if (t.empty()) {
                t += s[i];
            } else if (r == 0) {
                if (s[i] == t.back()) {
                    t.pop_back();
                } else {
                    t.push_back(s[i]);
                }
            } else {
                if (s[i] == t.front()) {
                    t.erase(t.begin());
                } else {
                    t = s[i] + t;
                }
            }
        }
    }
    if (r == 1) reverse(all(t));
    cout << t << endl;
    return 0;
}
