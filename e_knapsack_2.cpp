// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_e
// value-based 0/1 knapsack
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
  int64_t N, W;
  cin >> N >> W;

  struct Item {
    int64_t w, v;
  };

  vector<Item> items(N);
  int64_t totalValue = 0;

  for (int64_t i = 0; i < N; ++i) {
    cin >> items[i].w >> items[i].v;
    totalValue += items[i].v;
  }

  const int64_t INF = numeric_limits<int64_t>::max() / 4;

  // dp[i][v] is the minimum weight needed to
  // obtain exactly value v using the first i
  // items.
  vector<vector<int64_t>> dp(
    N + 1, vector<int64_t>(totalValue + 1, INF));

  // With no items, only value 0 can be obtained.
  dp[0][0] = 0;

  for (int64_t i = 1; i <= N; ++i) {
    for (int64_t v = 0; v <= totalValue; ++v) {
      // Do not take item i - 1.
      dp[i][v] = dp[i - 1][v];

      // Take item i - 1, if the remaining value
      // is valid.
      if (v >= items[i - 1].v) {
        dp[i][v] =
          min(dp[i][v], items[i - 1].w +
                          dp[i - 1][v - items[i - 1].v]);
      }
    }
  }

  int64_t answer = 0;

  // Find the greatest value whose minimum
  // required weight does not exceed the knapsack
  // capacity.
  for (int64_t v = 0; v <= totalValue; ++v) {
    if (dp[N][v] <= W) {
      answer = v;
    }
  }

  cout << answer << endl;

  return 0;
}
