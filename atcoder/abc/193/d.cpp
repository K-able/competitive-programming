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

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}
template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

int score(string s) {
    vector<int> a(10);
    for (char c : s) a[c-'0']++;
    int res = 0;
    rep(i,1,10) res += i * pow(10, a[i]);
    return res;
}

int main() {
    int k;
    string s, t;
    cin >> k >> s >> t;
    vector<int> c(10, k);
    c[0] = 0;
    rep(i,0,4) {
        c[s[i]-'0']--;
        c[t[i]-'0']--;
    }
    ll count = 0;
    rep(i,1,10) {
        rep(j,1,10) {
            s[4] = i + '0';
            t[4] = j + '0';
            if (score(s) > score(t)) {
                if (i == j) count += (ll)c[i]*(c[i]-1);
                else count += (ll)c[i]*c[j];
            }
        }
    }
    const ll p_all = 9 * k - 8;
    double ans = double(count) / p_all / (p_all - 1);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;    
    
    /*
    int k;
    string s, t;
    cin >> k >> s >> t;
    int s_val[5] = {int(s[0]-'0'), int(s[1]-'0'), int(s[2]-'0'), int(s[3]-'0'), 0};
    int t_val[5] = {int(t[0]-'0'), int(t[1]-'0'), int(t[2]-'0'), int(t[3]-'0'), 0};
    vector<int> s_card_num(10, 0);
    vector<int> t_card_num(10, 0);
    rep(i,0,4) {
        s_card_num[s_val[i]] += 1;
        t_card_num[t_val[i]] += 1;
    }
    ll count = 0;
    rep(i,1,10) {
        if (s_card_num[i] + t_card_num[i] >= k) continue;
        rep(j,1,10) {
            if (s_card_num[j] + t_card_num[j] >= k) continue;
            ll s_point = 0; ll t_point = 0;
            s_card_num[i] += 1;
            t_card_num[j] += 1;
            rep(k,1,10) {
                s_point += k * pow(10, s_card_num[k]);
                t_point += k * pow(10, t_card_num[k]);
            }
            s_card_num[i] -= 1;
            t_card_num[j] -= 1;
            if (s_point > t_point) count += (k - s_card_num[i] - t_card_num[i]) * (k - s_card_num[j] - t_card_num[j]);
        }
        
    }
    ll p_all = (9 * k - 8);
    double ans = double(count) / double(p_all) / double(p_all - 1);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
    */    
}
