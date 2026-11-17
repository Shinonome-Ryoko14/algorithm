#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    while (a[i] != 1) {
      a[i] >>= 1;
      cnt++;
    }
    b[i] = cnt;
  }

  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += b[i];
  }

  int ans = sum / 11 + 1;
  if (sum == 0) {
    ans = 0;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
