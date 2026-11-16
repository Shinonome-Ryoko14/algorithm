#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 calc(i64 x, const vector<i64> &L, const vector<i64> &R) {
  i64 cost = 0;
  for (int i = 0; i < L.size(); i++) {
    if (L[i] > x) {
      cost += (L[i] - x) * (L[i] - x);
    } else if (R[i] < x) {
      cost += (x - R[i]) * (x - R[i]);
    }
  }

  return cost;
}

void solve() {
  int n;
  cin >> n;
  vector<i64> L(n);
  vector<i64> R(n);
  for (int i = 0; i < n; i++) {
    cin >> L[i] >> R[i];
  }

  i64 L_max = *max_element(L.begin(), L.end());
  i64 R_min = *min_element(R.begin(), R.end());

  i64 l = R_min;
  i64 r = L_max;
  i64 ans = min(calc(l, L, R), calc(r, L, R));

  while (r - l > 3) {
    i64 m1 = l + (r - l) / 3;
    i64 m2 = r - (r - l) / 3;

    i64 cost1 = calc(m1, L, R);
    i64 cost2 = calc(m2, L, R);

    if (cost1 < cost2) {
      r = m2;
    } else {
      l = m1;
    }
  }

  for (i64 i = l; i <= r; i++) {
    ans = min(ans, calc(i, L, R));
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
