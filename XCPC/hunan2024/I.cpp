#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
  int n, k, m, q;
  cin >> n >> k >> m >> q;

  vector<bool> judge(n, false);
  vector<i64> x(m);
  for (int i = 0; i < m; i++) {
    cin >> x[i];
  }

  auto calc = [&](i64 base, int idx) {
    i64 res = 1;
    for (int i = 1; i <= idx; i++) {
      res = (res * base) % n;
    }
    return res;
  };

  for (int i = 0; i < m; i++) {
    for (int j = 1; j <= k; j++) {
      i64 num = calc(x[i], j);
      judge[num] = true;
    }
  }

  vector<bool> ans(q, true);
  for (int i = 0; i < q; i++) {
    int query;
    cin >> query;
    for (int j = 1; j <= k; j++) {
      i64 num = calc(query, j);
      if (judge[num] == false) {
        ans[i] = false;
        break;
      }
    }
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
