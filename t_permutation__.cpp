// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_t
// permutation dp, rank dp, prefix and suffix sums
// O(N^2) time, O(N) memory
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

  // dp[j] is the number of valid permutations of the
  // current length whose last element has rank j.
  vector<int64_t> dp(N);
  dp[0] = 1;

  for (int64_t i = 2; i <= N; ++i) {
    if (s[i - 2] == '<') {
      // new[j] = old[0] + ... + old[j - 1].
      // Sweep left to right while preserving the old value
      // before overwriting dp[j].
      int64_t prefix = 0;

      for (int64_t j = 0; j < i; ++j) {
        int64_t old = dp[j];

        dp[j] = prefix;

        prefix += old;
        prefix %= MOD;
      }
    } else {
      // new[j] = old[j] + ... + old[i - 2].
      // Sweep right to left so values still needed by the
      // suffix sum have not been overwritten.
      int64_t suffix = 0;

      for (int64_t j = i - 1; j >= 0; --j) {
        int64_t old = dp[j];

        suffix += old;
        suffix %= MOD;

        dp[j] = suffix;
      }
    }
  }

  int64_t answer = 0;
  for (int64_t j = 0; j < N; ++j) {
    answer += dp[j];
    answer %= MOD;
  }

  cout << answer << endl;

  return 0;
}
