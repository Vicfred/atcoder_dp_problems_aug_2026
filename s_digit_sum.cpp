// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_s
// digit dp, counting dp
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  const int64_t MOD = 1'000'000'007;

  string K;
  int64_t D;
  cin >> K >> D;

  int64_t L = static_cast<int64_t>(K.size());

  // dp[i][r][tight] is the number of ways to choose the
  // first i digits such that:
  //   - the digit sum modulo D is r
  //   - tight == 1 means the chosen prefix is equal to K's
  //   prefix
  //   - tight == 0 means the chosen prefix is already
  //   smaller
  vector<vector<vector<int64_t>>> dp(
    L + 1, vector<vector<int64_t>>(D, vector<int64_t>(2)));

  // Before choosing any digits, the sum is 0 and the empty
  // prefix is still equal to K's empty prefix.
  dp[0][0][1] = 1;

  for (int64_t i = 0; i < L; ++i) {
    int64_t limitDigit = K[i] - '0';

    for (int64_t r = 0; r < D; ++r) {
      for (int64_t tight = 0; tight <= 1; ++tight) {
        // If we are already smaller than K, any digit 0..9
        // is allowed. Otherwise we cannot exceed K[i].
        int64_t maxDigit = tight ? limitDigit : 9;

        for (int64_t digit = 0; digit <= maxDigit;
             ++digit) {
          int64_t newRemainder = (r + digit) % D;

          // We remain tight only if we were already tight
          // and choose exactly the corresponding digit of
          // K.
          int64_t newTight = tight && digit == limitDigit;

          dp[i + 1][newRemainder][newTight] +=
            dp[i][r][tight];

          dp[i + 1][newRemainder][newTight] %= MOD;
        }
      }
    }
  }

  // Remainder 0 means the digit sum is divisible by D.
  // Both numbers smaller than K and K itself are allowed.
  int64_t answer = (dp[L][0][0] + dp[L][0][1]) % MOD;

  // Leading zeros let the DP represent every number from 0
  // to K. The all-zero choice represents 0, but the problem
  // asks for integers from 1 to K, so remove it.
  answer = (answer - 1 + MOD) % MOD;

  cout << answer << endl;

  return 0;
}
