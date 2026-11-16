#include <bits/stdc++.h>
#include <vector>
using namespace std;
using i64 = long long;

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> i(n, {0, 0});
  for (int j = 0; j < n; j++) {
    int f = 0, s = 0;
    cin >> f >> s;
    i[j] = {f, s};
  }
  sort(i.begin(), i.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
  vector<int> m;
  vector<int> q;
  vector<int> vis(n, 1);
  int math = i[0].first;
  m.push_back(math);
  q.push_back(0);
  for (int j = 1; j < n; j++) {
    if (math == i[j].first) {
      continue;
    } else {
      math = i[j].first;
      q.push_back(j);
      m.push_back(math);
    }
  }
  int size = m.size();
  vector<int> s(size, 0);
  /*vector<int> q(size, 0);
  for (int j = 0; j < m.size(); j++) {
    auto it = lower_bound(i.begin(), i.end(), pair{m[j], 0});
    q[j] = it - i.begin();
  }*/
  int a = 0;
  i64 sum = 0;
  int bei = 1;
  while (a < n) {
    while (vis[a] == 0) {
      a++;
    }
    if (a == n) {
      break;
    }
    // int bei=1;
    int start = a;
    auto it = lower_bound(m.begin(), m.end(), i[start].first);
    int loc = it - m.begin();
    int loc_1 = loc + 1;
    vis[q[loc] + s[loc]] = 0;
    s[loc]++;
    /*if ( loc_1==q.size() ){
      if ( q[loc_1]+s[loc_1]<i.size() ){

      }
    } else
    */
    while (m[loc_1] == m[loc] + 1) {
      if (loc == m.size()) {
        if (q[loc] + s[loc] == n - 1) {
          sum += i[q[loc] + s[loc]].first * bei;
          vis[q[loc] + s[loc]] = 0;
          break;
        } else {
          bei++;
        }
      } else if (q[loc_1] + s[loc_1] == q[loc_1 + 1]) {
        sum += i[q[loc] + s[loc]].first * bei;
        vis[q[loc] + s[loc]] = 0;
        bei = 1;
        break;
      } else {
        bei++;
        sum += bei * i[q[loc_1] + s[loc_1]].first;
        vis[q[loc_1] + s[loc_1]] = 0;
        loc_1++, loc++;
        if (m[loc_1] != m[loc] + 1) {
          bei = 1;
        }
      }
    }
    if (m[loc_1] != m[loc] + 1) {
      sum += bei * i[q[loc] + s[loc]].first;
      bei = 1;
    }
  }
  cout << sum << endl;
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
