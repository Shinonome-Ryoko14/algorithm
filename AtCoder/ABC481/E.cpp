#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Point {
  i64 x, y;
};

i64 cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

// 按极角从小到大排序
int half(const Point &p) { return (p.y > 0 || (p.y == 0 && p.x > 0)) ? 0 : 1; }

bool cmp(const Point &a, const Point &b) {
  if (half(a) != half(b)) {
    return half(a) < half(b);
  }
  return cross(a, b) > 0;
}

void solve() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].x >> p[i].y;
    }

    sort(p.begin(), p.end(), cmp);

    // 复制一份，处理跨越极角边界的情况
    vector<Point> a(2 * n);
    for (int i = 0; i < n; i++) {
      a[i] = p[i];
      a[i + n] = p[i];
    }

    int ans = 0;
    int r = 0;

    for (int l = 0; l < n; l++) {
      r = max(r, l + 1);

      while (r < l + n && cross(a[l], a[r]) > 0) {
        r++;
      }

      ans = max(ans, r - l);
    }

    cout << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
  return 0;
}
