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

  // dp[h] is the probability of having exactly h
  // heads after processing the coins seen so far.
  vector<long double> dp(N + 1);
  dp[0] = 1.0L;

  for (int64_t i = 0; i < N; ++i) {
    // Iterate backward so dp[h - 1] still
    // represents the probabilities before
    // processing the current coin.
    for (int64_t h = i + 1; h >= 0; --h) {
      // Current coin is tails, so the number of
      // heads remains h.
      dp[h] *= 1.0L - p[i];

      // Current coin is heads, so we previously
      // had h - 1 heads.
      if (h > 0) {
        dp[h] += p[i] * dp[h - 1];
      }
    }
  }

  long double answer = 0.0L;

  // N is odd, so more heads than tails means
  // strictly more than N / 2 heads.
  for (int64_t h = N / 2 + 1; h <= N; ++h) {
    answer += dp[h];
  }

  cout << setprecision(18) << answer << endl;

  return 0;
}
