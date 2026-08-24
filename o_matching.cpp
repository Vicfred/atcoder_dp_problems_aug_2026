// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_o
// bitmask dp
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t N;
  cin >> N;

  vector<vector<char>> a(N, vector<char>(N));

  for (int64_t man = 0; man < N; ++man) {
    for (int64_t woman = 0; woman < N; ++woman) {
      int64_t value;
      cin >> value;
      a[man][woman] = static_cast<char>(value);
    }
  }

  // dp[mask] is the number of ways to match the first
  // popcount(mask) men using exactly the women in mask.
  vector<int64_t> dp(1LL << N);

  // There is exactly one way to match zero men with
  // zero women.
  dp[0] = 1;

  for (int64_t mask = 1; mask < (1LL << N); ++mask) {
    // If mask contains k women, this state represents
    // matching men 0..k-1, so man k-1 was matched last.
    int64_t man = __builtin_popcountll(mask) - 1;

    for (int64_t woman = 0; woman < N; ++woman) {
      // Try woman as the partner chosen for the last man.
      // She must belong to mask and be compatible with him.
      if ((mask & (1LL << woman)) && a[man][woman] == 1) {
        // Remove woman from mask to obtain the state before
        // the last pair was formed.
        int64_t previousMask = mask ^ (1LL << woman);

        dp[mask] += dp[previousMask];
        dp[mask] %= MOD;
      }
    }
  }

  // The full mask means every woman has been matched,
  // and therefore all N men have also been matched.
  cout << dp[(1LL << N) - 1] << endl;

  return 0;
}
