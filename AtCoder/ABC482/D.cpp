#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;

  vector<long long> X(N);
  for (int i = 0; i < N; i++)
    cin >> X[i];

  long long L = X[0], R = X[N - 1];

  for (int i = 0; i < N; i++) {
    long long ans;

    if (N == 1) {
      ans = 0;
    } else if (i == 0 || i == N - 1) {
      ans = (R - L) / 2;
    } else {
      long long cand1 = max((R - X[i]) / 2, (X[i + 1] - L) / 2);

      long long cand2 = max((X[i] - L) / 2, (R - X[i - 1]) / 2);

      ans = min(cand1, cand2);
    }

    cout << ans << '\n';
  }

  return 0;
}
