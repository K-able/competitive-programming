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
    // input
    int n, m, s;
    cin >> n >> m >> s;
    Graph g(n);
    rep(i,0,m) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back(Edge(b,w));
    }
    // dijkstra
    vector<ll> dist(n, INF);
    dist[s] = 0;
    /* simple method 
    vector<bool> used(n, false);
    rep(i,0,n) {
        // search v with min dist and non used
        ll min_dist = INF;
        int min_v = -1;
        rep(v,0,n) {
            if (!used[v] && dist[v] < min_dist) {
                min_dist = dist[v];
                min_v = v;
            }
        }
        if (min_v == -1) break;
        // change min based on min_v
        for (auto e : g[min_v]) chmin(dist[e.to], dist[min_v] + e.w);
        used[min_v] = true;
    }
    */
    // use priority_queue
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push(make_pair(dist[s], s));
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
    // output
    rep(v,0,n) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
    return 0;
}
