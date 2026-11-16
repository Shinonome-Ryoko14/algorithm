#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
  vector<string> mp(5);
  int cnt1 = 0, cnt2 = 0;

  for (int i = 0; i < 5; i++) {
    cin >> mp[i];
  }

  for (int i = 0; i < 5; i++) {
    if (mp[i][i] == '.') {
      cnt1++;
    }
    if (mp[i][4 - i] == '.') {
      cnt2++;
    }
  }

  int cnt3 = INT_MAX;
  for (int i = 0; i < 5; i++) {
    int tmp = 0;
    for (char c : mp[i]) {
      if (c == '.') {
        tmp++;
      }
    }
    cnt3 = min(cnt3, tmp);
  }

  int cnt4 = INT_MAX;
  for (int i = 0; i < 5; i++) {
    int tmp = 0;
    for (int j = 0; j < 5; j++) {
      if (mp[j][i] == '.') {
        tmp++;
      }
    }
    cnt4 = min(cnt4, tmp);
  }

  int ans = min(min(cnt1, cnt2), min(cnt3, cnt4));
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
