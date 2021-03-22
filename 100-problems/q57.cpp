#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Matrix = vector<vector<int>>;

const ll INF = LLONG_MAX;
const ld EPS = 1e-14;
const ll MOD = 1e9+7;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

template<class T> bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    else return false;
}

template<class T> bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    else return false;
}

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    int n, k;
    cin >> n >> k;
    Graph g(n);
    vector<int> ans;
    rep(i,0,k) {
        int q;
        cin >> q;
        if (q == 1) {
            int c, d, e;
            cin >> c >> d >> e;
            c--; d--;
            g[c].push_back(Edge(d,e));
            g[d].push_back(Edge(c,e));
        } else if (q == 0) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            // dijkstra
            vector<ll> dist(n, INF);
            dist[a] = 0;
            priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
            que.push(make_pair(dist[a], a));
            while (!que.empty()) {
                int v = que.top().second;
                ll d = que.top().first;
                que.pop();
                if (d > dist[v]) continue;  // used
                for (auto e : g[v]) {
                    if (chmin(dist[e.to], dist[v] + e.w)) {
                        que.push(make_pair(dist[e.to], e.to));
                    }
                }
            }
            if (dist[b] < INF) ans.push_back(dist[b]);
            else ans.push_back(-1);
        }
    }
    rep(i,0,ans.size()) cout << ans[i] << endl;
    return 0;
}
