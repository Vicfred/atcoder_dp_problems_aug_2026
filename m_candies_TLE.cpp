// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_m
// counting dp
#include <algorithm>
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
    for (int64_t k = 0; k <= K; ++k) {
      // Give x candies to child i. The previous i
      // - 1 children must then account for
      // exactly k - x candies.
      for (int64_t x = 0; x <= min(a[i - 1], k); ++x) {
        dp[i][k] += dp[i - 1][k - x];
        dp[i][k] %= MOD;
      }
    }
  }

  cout << dp[N][K] << endl;

  return 0;
}
