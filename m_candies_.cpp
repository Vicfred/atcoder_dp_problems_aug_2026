// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_m
// counting dp with sliding window
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

  dp[0][0] = 1;

  for (int64_t i = 1; i <= N; ++i) {
    // window is the sum of the valid states from
    // the previous row:
    //
    // dp[i - 1][max(0, k - a[i - 1]) ... k]
    int64_t window = 0;

    for (int64_t k = 0; k <= K; ++k) {
      // This state enters the right side of the
      // window.
      window += dp[i - 1][k];
      window %= MOD;

      // Once the window contains a state
      // corresponding to giving more than a[i -
      // 1] candies to child i, remove that state
      // from the left side.
      int64_t leaving = k - a[i - 1] - 1;

      if (leaving >= 0) {
        window -= dp[i - 1][leaving];

        if (window < 0) {
          window += MOD;
        }
      }

      dp[i][k] = window;
    }
  }

  cout << dp[N][K] << endl;

  return 0;
}
