    #include <bits/stdc++.h>
    #define rep(i,n) for (int i = 0; i < (n); ++i)
    #define all(x) (x).begin(), (x).end()
    using namespace std;
    using ll = long long;
    using ld = long double;
    using P = pair<int, int>;

    const ll INF = LLONG_MAX;
    const ld eps = 1e-14;

    int main() {
        ld p;
        cin >> p;
        // Differential calculus
        /*
        ld x = max((ld)0, logl(p*logl(2)/1.5)*1.5/logl(2));
        ld y = p * powl((ld)2, x/(-1.5)) + x;
        cout << fixed << setprecision(10) << y << endl;
        */
        // Ternary search tree 
        ld left = 0;
        ld right = 1e18;
        while (right - left > 1e-10) {
            ld c1 = left + (right - left) / 3;
            ld c2 = right - (right - left) / 3;
            if (p * powl((ld)2, c1/(-1.5)) + c1 < p * powl((ld)2, c2/(-1.5)) + c2) {
                right = c2;
            } else {
                left = c1;
            }
        }
        cout << fixed << setprecision(10) << p * powl((ld)2, right/(-1.5)) + right << endl;

        return 0;
    }
