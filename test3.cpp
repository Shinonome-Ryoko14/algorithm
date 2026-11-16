#include <bits/stdc++.h>
using i64 = long long;

i64 isqrt(i64 x) {
  i64 k = std::sqrt(x);

  while (k * k > x) {
    k--;
  }

  while ((k + 1) * (k + 1) <= x) {
    k++;
  }

  return k;
}

void solve() {
  int t;
  std::cin >> t;
  while (t--) {
    i64 x;
    std::cin >> x;
    if (x == 0) {
      std::cout << 0 << "\n";
      continue;
    }

    i64 a = isqrt(x);
    i64 ans = x;

    while (1 <= a) {
      i64 b = x / a;
      i64 c = x - a * b;

      i64 cur_max = std::max({a, b, c});
      i64 cur_min = std::min({a, b, c});
      ans = std::min(ans, cur_max - cur_min);

      if (b - 1 >= 0) {
        i64 b2 = b - 1;
        i64 c2 = x - a * b2;
        i64 cur_max2 = std::max({a, b2, c2});
        i64 cur_min2 = std::min({a, b2, c2});
        ans = std::min(ans, cur_max2 - cur_min2);
      }

      if (b - a > ans) {
        break;
      }

      a--;
    }

    std::cout << ans << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  solve();

  return 0;
}
