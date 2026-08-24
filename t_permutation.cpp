// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_t
// permutation dp, rank dp, prefix sums
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t N;
  cin >> N;

  string s;
  cin >> s;

  // dp[i][j] is the number of valid permutations of length
  // i whose last element has rank j among those i elements.
  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(N));

  // There is only one permutation of length 1, and its only
  // element has rank 0.
  dp[1][0] = 1;

  for (int64_t i = 2; i <= N; ++i) {
    // prefix[x] is the sum of dp[i - 1][0..x - 1].
    //
    // These prefix sums replace the innermost loop of the
    // O(N^3) solution.
    vector<int64_t> prefix(i);
    for (int64_t k = 0; k <= i - 2; ++k) {
      prefix[k + 1] = prefix[k] + dp[i - 1][k];
      prefix[k + 1] %= MOD;
    }

    for (int64_t j = 0; j < i; ++j) {
      if (s[i - 2] == '<') {
        // dp[i][j] =
        //   dp[i - 1][0] + ... + dp[i - 1][j - 1].
        dp[i][j] = prefix[j];
      } else {
        // dp[i][j] =
        //   dp[i - 1][j] + ... + dp[i - 1][i - 2].
        dp[i][j] = (prefix[i - 1] - prefix[j] + MOD) % MOD;
      }
    }
  }

  // The final element may have any rank.
  int64_t answer = 0;
  for (int64_t j = 0; j < N; ++j) {
    answer += dp[N][j];
    answer %= MOD;
  }

  cout << answer << endl;

  return 0;
}
