#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

const ld eps = 1e-14;

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<int> q(n);
    vector<int> perm(n);
    rep(i,n) {
        cin >> p[i];
        perm[i] = i+1;
    }
    rep(i,n) cin >> q[i];
    int a, b;
    int cnt = 0;
    do {
        cnt++;
        bool p_flg = true; bool q_flg = true;
        rep(i,n) {
            if (p[i] != perm[i]) p_flg = false;
            if (q[i] != perm[i]) q_flg = false;
        }
        if (p_flg) a = cnt;
        if (q_flg) b = cnt;
    } while(next_permutation(perm.begin(), perm.end()));
    cout << abs(a - b) << endl;
    
    return 0;
}
