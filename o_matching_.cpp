// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_o
// bitmask dp
#include <bit>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t N;
  cin >> N;

  vector<vector<int64_t>> a(N, vector<int64_t>(N));

  for (int64_t man = 0; man < N; ++man) {
    for (int64_t woman = 0; woman < N; ++woman) {
      cin >> a[man][woman];
    }
  }

  int64_t totalMasks = 1LL << N;

  // dp[mask] is the number of ways to match the first
  // popcount(mask) men using exactly the women in mask.
  vector<int64_t> dp(totalMasks);

  // There is exactly one way to match zero men:
  // choose nobody.
  dp[0] = 1;

  for (int64_t mask = 0; mask < totalMasks; ++mask) {
    int64_t man = static_cast<int64_t>(
      popcount(static_cast<uint64_t>(mask)));

    // The full mask has no next man to match.
    if (man == N) {
      continue;
    }

    for (int64_t woman = 0; woman < N; ++woman) {
      // Woman must be unused and compatible with
      // the next man.
      if ((mask & (1LL << woman)) == 0 &&
          a[man][woman] == 1) {
        int64_t newMask = mask | (1LL << woman);

        dp[newMask] += dp[mask];
        dp[newMask] %= MOD;
      }
    }
  }

  cout << dp[totalMasks - 1] << endl;

  return 0;
}
