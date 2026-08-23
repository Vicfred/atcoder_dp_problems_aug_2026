// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_l
// interval dp, game dp, prefix sums
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;

  vector<int64_t> a(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> a[i];
  }

  // prefix[i] is the sum of a[0..i - 1].
  // Therefore the sum of a[l..r] is
  // prefix[r + 1] - prefix[l].
  vector<int64_t> prefix(N + 1);
  for (int64_t i = 1; i <= N; ++i) {
    prefix[i] = prefix[i - 1] + a[i - 1];
  }

  // dp[l][r] is the maximum total score the
  // player whose turn it is can obtain from
  // interval [l, r].
  vector<vector<int64_t>> dp(N, vector<int64_t>(N));

  for (int64_t i = 0; i < N; ++i) {
    dp[i][i] = a[i];
  }

  // Smaller intervals must be solved first
  // because [l, r] depends on [l + 1, r] and [l,
  // r - 1].
  for (int64_t length = 2; length <= N; ++length) {
    for (int64_t l = 0; l + length <= N; ++l) {
      int64_t r = l + length - 1;

      // If we take a[l], the opponent plays
      // optimally on [l + 1, r]. Whatever the
      // opponent does not obtain from that
      // remaining interval eventually belongs to
      // us.
      int64_t remainingLeft = prefix[r + 1] - prefix[l + 1];

      int64_t takeLeft =
          a[l] + remainingLeft - dp[l + 1][r];

      // Symmetrically, taking a[r] leaves [l, r -
      // 1] for the opponent.
      int64_t remainingRight = prefix[r] - prefix[l];

      int64_t takeRight =
          a[r] + remainingRight - dp[l][r - 1];

      dp[l][r] = max(takeLeft, takeRight);
    }
  }

  // dp[0][N - 1] is First's optimal total score
  // X. Since X + Y is the total sum, X - Y = 2X -
  // total.
  int64_t firstScore = dp[0][N - 1];
  int64_t total = prefix[N];

  cout << 2 * firstScore - total << endl;

  return 0;
}
