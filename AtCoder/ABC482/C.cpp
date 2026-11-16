#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
  i64 H, W, N, Q;
  cin >> H >> W >> N >> Q;

  vector<int> x(N), y(N);

  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
  }

  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  while (Q--) {
    int tp, l, r;
    cin >> tp >> l >> r;

    if (tp == 1) {
      auto L = lower_bound(x.begin(), x.end(), l);
      auto R = upper_bound(x.begin(), x.end(), r);

      cout << R - L << '\n';
    } else {
      auto L = lower_bound(y.begin(), y.end(), l);
      auto R = upper_bound(y.begin(), y.end(), r);

      cout << R - L << '\n';
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
