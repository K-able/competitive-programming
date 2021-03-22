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

vector<int> bfs(const Matrix g, int s) {
    int n = (int)g.size();
    vector<int> dist(n, -1);
    queue<int> que;
    dist[s] = 0;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int x : g[v]) {
            if (dist[x] != -1) continue;
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }
    return dist;
}

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    // input
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    int p, q;
    cin >> p >> q;
    vector<int> z_tmp(k);
    rep(i,0,k) {
        cin >> z_tmp[i];
        z_tmp[i]--;
    }
    Matrix g_tmp(n);
    rep(i,0,m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g_tmp[a].push_back(b);
        g_tmp[b].push_back(a);
    }
    // 0 -> normal, 1 -> danger, -1 -> zonbi
    vector<int> z(n, 0);
    rep(i,0,k) {
        vector<int> dist = bfs(g_tmp, z_tmp[i]);
        rep(j,0,n) if (dist[j] <= s) z[j] = 1;
    }
    rep(i,0,k) z[z_tmp[i]] = -1;
    // make Graph
    Graph g(n);
    rep(a,0,n) {
        vector<int> b_list = g_tmp[a]; 
        for (int b : b_list) {
            if (b == n-1) g[a].push_back(Edge(b, 0));
            else if (z[b] == 0) g[a].push_back(Edge(b, p));
            else if (z[b] == 1) g[a].push_back(Edge(b, q));
        }
    }
    // dijkstra
    vector<ll> dist2(n, INF);
    dist2[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push(make_pair(dist2[0], 0));
    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();
        if (d > dist2[v]) continue;  // used
        for (auto e : g[v]) {
            if (chmin(dist2[e.to], dist2[v] + e.w)) {
                que.push(make_pair(dist2[e.to], e.to));
            }
        }
    }
    // output
    cout << dist2[n-1] << endl;
    return 0;
}
