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

  // dp[i][k] is the number of ways to distribute
  // exactly k candies among the first i children.
  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(K + 1));

  // There is exactly one way to distribute zero
  // candies among zero children.
  dp[0][0] = 1;

  for (int64_t i = 1; i <= N; ++i) {
    // prefix[k] is the sum of dp[i - 1][0..k]
    // This lets us calculate each transition as a
    // range sum.
    vector<int64_t> prefix(K + 1);
    prefix[0] = dp[i - 1][0];

    for (int64_t k = 1; k <= K; ++k) {
      prefix[k] = (prefix[k - 1] + dp[i - 1][k]) % MOD;
    }

    for (int64_t k = 0; k <= K; ++k) {
      // The previous children may have received
      // any total from max(0, k - a[i - 1])
      // through k.
      int64_t left = k - a[i - 1];

      dp[i][k] = prefix[k];

      if (left > 0) {
        dp[i][k] -= prefix[left - 1];

        if (dp[i][k] < 0) {
          dp[i][k] += MOD;
        }
      }
    }
  }

  cout << dp[N][K] << endl;

  return 0;
}
