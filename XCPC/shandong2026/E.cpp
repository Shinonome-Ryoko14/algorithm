#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

// 构造一维长度 L 的合法排列，L >= 5
void fill1D(vector<int> &v, int L) {
  int p = 0;

  // 先放所有偶数：0,2,4,...
  for (int x = 0; x < L; x += 2) {
    v[p++] = x;
  }

  if (L % 2 == 1) {
    // L 为奇数：0,2,4,...,1,3,5,...
    for (int x = 1; x < L; x += 2) {
      v[p++] = x;
    }
  } else {
    // L 为偶数：需要调整最后两个奇数，避免末尾和 0 连续
    // 形如：0,2,4,...,1,3,...,L-1,L-3
    for (int x = 1; x <= L - 5; x += 2) {
      v[p++] = x;
    }
    v[p++] = L - 1;
    v[p++] = L - 3;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;

  // 只有这些很小的局面无解
  set<pii> bad = {{1, 2}, {2, 1}, {1, 3}, {3, 1}, {1, 4}, {4, 1}, {2, 2}};

  while (T--) {
    int n, m;
    cin >> n >> m;

    if (bad.count({n, m})) {
      cout << "No\n";
      continue;
    }

    cout << "Yes\n";

    // 统一成 n <= m，最后如果需要再转置输出
    bool transposed = false;
    if (n > m) {
      transposed = true;
      swap(n, m);
    }

    vector<vector<int>> a(n, vector<int>(m));

    if (n == 1) {
      fill1D(a[0], m);
    } else {
      int num = 0;

      // 两行一组，交错填充
      for (int i = 0; i + 1 < n; i += 2) {
        // 第一遍：在两行之间上下交替
        for (int k = 0; k < m; k++) {
          a[i + (k & 1)][k] = num++;
        }

        // 第二遍：填另一批位置
        for (int k = 0; k < m; k++) {
          a[i + 1 - (k & 1)][k] = num++;
        }
      }

      // 如果 n 是奇数，最后一行单独修补
      if (n & 1) {
        int i = n - 1;

        for (int k = 0; k < m; k++) {
          if (k == 0 || a[i][k - 1] != num - 1) {
            a[i][k] = num++;
          } else {
            // 当前数和左边连续，会相邻；交换首行同列元素来打断
            a[i][k] = a[0][k];
            a[0][k] = num++;
          }
        }
      }
    }

    // 统一输出
    if (!transposed) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          cout << a[i][j] << " \n"[j + 1 == m];
        }
      }
    } else {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          cout << a[j][i] << " \n"[j + 1 == n];
        }
      }
    }
  }

  return 0;
}
