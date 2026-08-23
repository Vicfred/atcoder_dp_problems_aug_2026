// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_m
// counting dp with prefix sums
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t N, K;
  cin >> N >> K;

  vector<int64_t> a(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> a[i];
  }

  // dp[k] is the number of ways to distribute exactly
  // k candies among the children processed so far.
  vector<int64_t> dp(K + 1);
  dp[0] = 1;

  for (int64_t i = 0; i < N; ++i) {
    // Convert the previous DP row into prefix sums.
    for (int64_t k = 1; k <= K; ++k) {
      dp[k] += dp[k - 1];
      dp[k] %= MOD;
    }

    // Convert each prefix sum into the required range sum.
    // Iterate backward so smaller prefix values remain
    // unchanged until they have been used.
    for (int64_t k = K; k >= 0; --k) {
      int64_t beforeLeft = k - a[i] - 1;

      if (beforeLeft >= 0) {
        dp[k] -= dp[beforeLeft];

        if (dp[k] < 0) {
          dp[k] += MOD;
        }
      }
    }
  }

  cout << dp[K] << endl;

  return 0;
}
