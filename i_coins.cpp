// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_i
// probability dp
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;

  vector<long double> p(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> p[i];
  }

  // dp[i][h] is the probability of getting
  // exactly h heads after tossing the first i
  // coins.
  vector<vector<long double>> dp(
      N + 1, vector<long double>(N + 1));

  // Before tossing any coins, we have exactly
  // zero heads with probability 1.
  dp[0][0] = 1.0L;

  for (int64_t i = 1; i <= N; ++i) {
    for (int64_t h = 0; h <= i; ++h) {
      // Coin i is tails, so we already had h
      // heads.
      dp[i][h] = (1.0L - p[i - 1]) * dp[i - 1][h];

      // Coin i is heads, so we previously had h -
      // 1 heads.
      if (h > 0) {
        dp[i][h] += p[i - 1] * dp[i - 1][h - 1];
      }
    }
  }

  long double answer = 0.0L;

  // Since N is odd, more heads than tails means
  // strictly more than N / 2 heads.
  for (int64_t h = N / 2 + 1; h <= N; ++h) {
    answer += dp[N][h];
  }

  cout << setprecision(18) << answer << endl;

  return 0;
}
