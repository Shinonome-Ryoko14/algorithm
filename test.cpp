#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

// hunan2024I
// 思路按照题目要求的通过transfer函数计算出num[i]
// 的转换值，并将a[i]对应的值变为true；
// 所以要再次使用一个二维数组来存num中不同变量对应的判断值
// 最后再q次依次判断将结果存入ans中
int transfer(int idx, int x, int n) {
  x = pow(x, idx);
  x %= n;
  return x;
}

void solve() {
  int n, k, m, q;
  cin >> n >> k >> m >> q;
  vector<bool> a(n, false);
  vector<int> num(m);
  for (int i = 0; i < m; i++) {
    cin >> num[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      int index = transfer(j, num[i], n);
      a[index] = true;
    }
  }

  vector<int> query(q);
  for (int i = 0; i < q; i++) {
    cin >> query[i];
  }

  vector<bool> ans(q, false);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();
  return 0;
}
