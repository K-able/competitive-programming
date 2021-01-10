#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    double w, h, x, y;
    cin >> w >> h >> x >> y;
    int ans = (x*2 == w && y*2 == h) ? 1 : 0;
    printf("%f %d", w*h/2, ans);
    
    return 0;
}
