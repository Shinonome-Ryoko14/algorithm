#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 INF = 1e18;

struct DSU {
  vector<int> parent;
  DSU(int n) {
    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  bool unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry)
      return false;
    parent[rx] = ry;
    return true;
  }
};

struct Edge {
  int u, v;
  i64 w;
  bool operator<(const Edge &other) const { return w < other.w; }
};

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<bool> is_spec(n + 1, false);
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    is_spec[x] = true;
  }

  vector<Edge> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    i64 w;
    cin >> u >> v >> w;
    if (u == v)
      continue;
    edges.push_back({u, v, w});
  }

  if (n == k) {
    if (n == 2) {
      i64 ans = INF;
      for (auto &e : edges)
        ans = min(ans, e.w);
      if (ans == INF)
        cout << -1 << "\n";
      else
        cout << ans << "\n";
    } else {
      cout << -1 << "\n";
    }
    return;
  }

  vector<Edge> nn_edges, sn_edges;
  for (auto &e : edges) {
    if (!is_spec[e.u] and !is_spec[e.v]) {
      nn_edges.push_back(e);
    } else if (is_spec[e.u] != is_spec[e.v]) {
      sn_edges.push_back(e);
    }
  }

  DSU dsu(n);
  i64 ans = 0;
  sort(nn_edges.begin(), nn_edges.end());
  for (auto &e : nn_edges) {
    if (dsu.unite(e.u, e.v)) {
      ans += e.w;
    }
  }

  int root = -1;
  for (int i = 1; i <= n; i++) {
    if (!is_spec[i]) {
      if (root == -1)
        root = dsu.find(i);
      else if (dsu.find(i) != root) {
        cout << -1 << "\n";
        return;
      }
    }
  }

  vector<i64> min_w(n + 1, INF);
  for (auto &e : sn_edges) {
    if (is_spec[e.u])
      min_w[e.u] = min(min_w[e.u], e.w);
    if (is_spec[e.v])
      min_w[e.v] = min(min_w[e.v], e.w);
  }

  for (int i = 1; i <= n; i++) {
    if (is_spec[i]) {
      if (min_w[i] == INF) {
        cout << -1 << "\n";
        return;
      }

      ans += min_w[i];
    }
  }

  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
