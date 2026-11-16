#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    if ((n == 1 and m == 2) or (n == 2 and m == 1)) {
      cout << "No\n";
      continue;
    } else if ((n == 1 and m == 3) or (n == 3 and m == 1)) {
      cout << "No\n";
      continue;
    } else if ((n == 1 and m == 4) or (n == 4 and m == 1)) {
      cout << "No\n";
      continue;
    } else if (n == 2 and m == 2) {
      cout << "No\n";
      continue;
    } else {
      cout << "Yes\n";
    }

    int num = 0;
    bool flip = false;
    if (n > m) {
      flip = true;
      swap(n, m);
    }
    vector<vector<int>> mp(n, vector<int>(m, 0));
    if (n == 1) {
      int num = 0;
      for (int i = 0; i < m; i++) {
        mp[0][i] = num;
        num += 2;
        if (num >= m) {
          num = 1;
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << mp[i][j] << " ";
        }
        cout << "\n";
      }
      continue;
    }
    if (m == 1) {
      int num = 0;
      for (int i = 0; i < n; i++) {
        mp[i][0] = num;
        num += 2;
        if (num >= n) {
          num = 1;
        }
      }
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << mp[i][j] << " ";
        }
        cout << "\n";
      }
      continue;
    }

    int i = 0;
    while (i < n) {
      if (n - i == 1) {
        int k = 0;
        while (k < m) {
          if (k == 0) {
            mp[i][k] = num;
          } else {
            if (mp[i][k - 1] == num - 1) {
              mp[i][k] = mp[0][k];
              mp[0][k] = num;
            } else
              mp[i][k] = num;
          }
          k++;
          num++;
        }
      } else {
        int a = i;
        int j = 0;
        for (int k = 0; k < m; k++) {
          mp[a][j] = num;
          num++;
          j++;

          if (a % 2 == 0) {
            a = a + 1;
          } else {
            a--;
          }
        }
        a = i + 1;
        j = 0;
        for (int k = 0; k < m; k++) {
          mp[a][j] = num;
          num++;
          j++;

          if (a % 2 == 0) {
            a = a + 1;
          } else {
            a--;
          }
        }
      }
      i += 2;
    }

    if (!flip) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << mp[i][j] << " ";
        }
        cout << "\n";
      }
    } else {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cout << mp[j][i] << " ";
        }
        cout << "\n";
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
