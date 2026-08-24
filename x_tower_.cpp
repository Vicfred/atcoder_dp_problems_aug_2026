// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_x
// knapsack dp, sorting by weight + solidness
// O(N * MAXW) time, O(MAXW) memory
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
  // bottom block, so no valid state can exceed this bound.
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

  // dp[w] is the maximum value of a valid tower with
  // total weight exactly w using blocks processed so far.
  vector<int64_t> dp(MAXW + 1, NEG);
  dp[0] = 0;

  for (const Block &block : blocks) {
    // The existing tower can be placed above this block
    // only if its total weight is at most block.s.
    //
    // Iterate backward so states created using this block
    // cannot be used again during the same iteration.
    for (int64_t w = block.s; w >= 0; --w) {
      if (dp[w] == NEG) {
        continue;
      }

      dp[w + block.w] =
        max(dp[w + block.w], dp[w] + block.v);
    }
  }

  int64_t answer = 0;
  for (int64_t w = 0; w <= MAXW; ++w) {
    answer = max(answer, dp[w]);
  }

  cout << answer << endl;

  return 0;
}
