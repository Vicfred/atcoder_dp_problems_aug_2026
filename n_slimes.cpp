// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_n
// interval dp, prefix sums
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;

  vector<int64_t> a(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> a[i];
  }

  // prefix[i] is the sum of a[0..i - 1].
  // Therefore the total size of a[l..r] is
  // prefix[r + 1] - prefix[l].
  vector<int64_t> prefix(N + 1);
  for (int64_t i = 1; i <= N; ++i) {
    prefix[i] = prefix[i - 1] + a[i - 1];
  }

  const int64_t INF = numeric_limits<int64_t>::max() / 4;

  // dp[l][r] is the minimum cost needed to merge
  // all slimes in a[l..r] into one slime.
  vector<vector<int64_t>> dp(N, vector<int64_t>(N, INF));

  for (int64_t i = 0; i < N; ++i) {
    dp[i][i] = 0;
  }

  // Each interval depends only on shorter
  // intervals.
  for (int64_t length = 2; length <= N; ++length) {
    for (int64_t l = 0; l + length <= N; ++l) {
      int64_t r = l + length - 1;
      int64_t mergeCost = prefix[r + 1] - prefix[l];

      // Try every possible final split:
      //
      // a[l..k] | a[k + 1..r]
      for (int64_t k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r],
                       dp[l][k] + dp[k + 1][r] + mergeCost);
      }
    }
  }

  cout << dp[0][N - 1] << endl;

  return 0;
}
