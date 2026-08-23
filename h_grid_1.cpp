// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_h
// grid counting dp
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t H, W;
  cin >> H >> W;

  vector<string> grid(H);
  for (int64_t i = 0; i < H; ++i) {
    cin >> grid[i];
  }

  const int64_t MOD = 1'000'000'007;

  // dp[i][j] is the number of ways to reach cell
  // (i, j) from (0, 0), moving only right or
  // down.
  vector<vector<int64_t>> dp(H, vector<int64_t>(W));

  // There is exactly one way to start at the
  // initial cell.
  dp[0][0] = 1;

  for (int64_t i = 0; i < H; ++i) {
    for (int64_t j = 0; j < W; ++j) {
      // Blocked cells cannot be part of any path.
      if (grid[i][j] == '#') {
        continue;
      }

      // Any path reaching this cell must come
      // either from the cell above or from the
      // cell to the left.
      if (i > 0) {
        dp[i][j] += dp[i - 1][j];
        dp[i][j] %= MOD;
      }

      if (j > 0) {
        dp[i][j] += dp[i][j - 1];
        dp[i][j] %= MOD;
      }
    }
  }

  cout << dp[H - 1][W - 1] << endl;

  return 0;
}
