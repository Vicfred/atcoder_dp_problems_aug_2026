// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_n
// interval dp, knuth optimization, prefix sums
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
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
  // Therefore the total size of a[l..r] is
  // prefix[r + 1] - prefix[l].
  vector<int64_t> prefix(N + 1);
  for (int64_t i = 1; i <= N; ++i) {
    prefix[i] = prefix[i - 1] + a[i - 1];
  }

  const int64_t INF = numeric_limits<int64_t>::max() / 4;

  // dp[l][r] is the minimum cost needed to merge
  // all slimes in a[l..r] into one slime.
  vector<vector<int64_t>> dp(N, vector<int64_t>(N, INF));

  // opt[l][r] stores an optimal final split k for a[l..r]:
  //
  // a[l..k] | a[k + 1..r]
  //
  // Knuth optimization gives:
  //
  // opt[l][r - 1] <= opt[l][r] <= opt[l + 1][r].
  vector<vector<int64_t>> opt(N, vector<int64_t>(N));

  for (int64_t i = 0; i < N; ++i) {
    dp[i][i] = 0;

    // A single slime has no real split, but using i here
    // gives the correct Knuth bounds for intervals of
    // length 2.
    opt[i][i] = i;
  }

  // As in the ordinary interval DP, shorter intervals must
  // be computed before longer ones.
  for (int64_t length = 2; length <= N; ++length) {
    for (int64_t l = 0; l + length <= N; ++l) {
      int64_t r = l + length - 1;

      // The final merge always costs the total size of
      // a[l..r], regardless of the final split position.
      int64_t mergeCost = prefix[r + 1] - prefix[l];

      // Without Knuth optimization we would try every
      // k from l through r - 1.
      //
      // Monotonicity of the optimal split lets us restrict
      // the search to the optimal splits of neighboring
      // smaller intervals.
      int64_t firstSplit = max(l, opt[l][r - 1]);
      int64_t lastSplit = min(r - 1, opt[l + 1][r]);

      for (int64_t k = firstSplit; k <= lastSplit; ++k) {
        int64_t cost = dp[l][k] + dp[k + 1][r] + mergeCost;

        if (cost < dp[l][r]) {
          dp[l][r] = cost;
          opt[l][r] = k;
        }
      }
    }
  }

  cout << dp[0][N - 1] << endl;

  return 0;
}
