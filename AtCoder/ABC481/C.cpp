#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
  int Q;
  cin >> Q;
  unordered_map<string, int> hs;
  int id = 0;

  for (int i = 0; i < Q; i++) {
    string s;
    cin >> s;
    int sz = hs.size();
    hs.insert({s, 0});
    if (hs.size() != sz) {
      id++;
      hs[s] = id;
    }
    cout << hs[s] << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
