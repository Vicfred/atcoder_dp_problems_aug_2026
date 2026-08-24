// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_x
// knapsack dp, sorting
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;

  struct Block {
    int64_t w, s, v;
  };

  vector<Block> blocks(N);

  // Any valid tower has total weight at most w + s of its
  // bottom block, so no valid DP state can exceed this
  // bound.
  int64_t MAXW = 0;
  for (auto &block : blocks) {
    cin >> block.w >> block.s >> block.v;
    MAXW = max(MAXW, block.w + block.s);
  }

  // Any valid tower can be reordered into increasing w + s
  // from top to bottom without losing feasibility.
  sort(blocks.begin(), blocks.end(),
       [](const Block &a, const Block &b) {
         return a.w + a.s < b.w + b.s;
       });

  const int64_t NEG = numeric_limits<int64_t>::min() / 4;

  // dp[i][w] is the maximum value of a valid tower using
  // some of the first i sorted blocks and having total
  // weight exactly w.
  vector<vector<int64_t>> dp(
    N + 1, vector<int64_t>(MAXW + 1, NEG));

  // The empty tower has weight 0 and value 0.
  dp[0][0] = 0;

  for (int64_t i = 1; i <= N; ++i) {
    const Block &block = blocks[i - 1];

    for (int64_t w = 0; w <= MAXW; ++w) {
      if (dp[i - 1][w] == NEG) {
        continue;
      }

      // Skip the current block.
      dp[i][w] = max(dp[i][w], dp[i - 1][w]);

      // If the current tower weighs at most block.s, this
      // block can be placed underneath the whole tower.
      if (w <= block.s) {
        dp[i][w + block.w] =
          max(dp[i][w + block.w], dp[i - 1][w] + block.v);
      }
    }
  }

  // The optimal tower may have any total weight.
  int64_t answer = 0;
  for (int64_t w = 0; w <= MAXW; ++w) {
    answer = max(answer, dp[N][w]);
  }

  cout << answer << endl;

  return 0;
}
