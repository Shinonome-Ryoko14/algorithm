// 难度四
#include <bits/stdc++.h>
using i64 = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> b(n);
  std::map<int, int> cnt;
  int mx = 0;

  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    cnt[b[i]]++;
    mx = std::max(mx, b[i]);
  }

  int M = 0;
  while (cnt.count(M)) {
    M++;
  }

  if (M <= mx) {
    std::cout << M + 1 << "\n";
  } else {
    std::vector<int> f(M);
    for (int i = 0; i < M; i++) {
      f[i] = cnt[i];
    }

    i64 max_mex = 0;

    while (max_mex < n) {
      int r = max_mex % M;
      if (f[r] > 0) {
        f[r]--;
        max_mex++;
      } else {
        break;
      }
    }

    std::cout << max_mex + 1 << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
