#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;

  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }

  int ans = 0;

  for (int i = 1; i < N; i++) {
    int low = min(A[i], A[i + 1]);
    int high = max(A[i], A[i + 1]);

    if (low <= K && K <= high) {
      ans++;
    }
  }

  for (int i = 2; i <= N - 1; i++) {
    if (A[i] == K) {
      ans--;
    }
  }

  cout << ans << '\n';
  return 0;
}
