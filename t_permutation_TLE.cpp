// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_t
// permutation dp, rank dp
// O(N^3) TLE
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
  //
  // The ranks are 0..i-1, so we only care about relative
  // order, not about the actual values used in the
  // permutation.
  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(N));

  // There is only one permutation of length 1, and its only
  // element necessarily has rank 0.
  dp[1][0] = 1;

  for (int64_t i = 2; i <= N; ++i) {
    for (int64_t j = 0; j < i; ++j) {
      if (s[i - 2] == '<') {
        // The previous last value must be smaller than the
        // new last value of rank j. Removing the new value
        // does not change the ranks of values below j.
        for (int64_t k = 0; k < j; ++k) {
          dp[i][j] += dp[i - 1][k];
          dp[i][j] %= MOD;
        }
      } else {
        // The previous last value must be larger than the
        // new last value of rank j. After removing the new
        // value, all larger ranks decrease by one, so they
        // correspond to ranks j..i-2 in the previous row.
        for (int64_t k = j; k <= i - 2; ++k) {
          dp[i][j] += dp[i - 1][k];
          dp[i][j] %= MOD;
        }
      }
    }
  }

  // The last element may have any rank.
  int64_t answer = 0;
  for (int64_t j = 0; j < N; ++j) {
    answer += dp[N][j];
    answer %= MOD;
  }

  cout << answer << endl;

  return 0;
}
