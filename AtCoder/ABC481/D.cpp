#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int n, m, s, t;
vector<vector<int>> road;
vector<int> dist;
vector<int> minTo;

int bfs(int s, int t) {
  deque<pair<int, int>> dq;
  dq.push_front({s, 0});
  dist[s] = 0;

  while (!dq.empty()) {
    auto [u, d] = dq.front();
    dq.pop_front();

    if (d != dist[u])
      continue;

    for (int v : road[u]) {
      int w = (v == minTo[u] ? 0 : 1);
      int nd = d + w;

      if (nd < dist[v]) {
        dist[v] = nd;

        if (w == 0) {
          dq.push_front({v, nd});
        } else if (w == 1) {
          dq.push_back({v, nd});
        }
      }
    }
  }

  return dist[t] == INT_MAX ? -1 : dist[t];
}

void solve() {
  cin >> n >> m >> s >> t;
  road.assign(n + 1, {});
  dist.assign(n + 1, INT_MAX);
  minTo.assign(n + 1, INT_MAX);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    road[u].push_back(v);
    minTo[u] = min(minTo[u], v);
  }

  int ans = bfs(s, t);
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
