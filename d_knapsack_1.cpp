// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_d
// 0/1 knapsack
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N, W;
  cin >> N >> W;

  struct Item {
    int64_t w, v;
  };

  vector<Item> items(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> items[i].w >> items[i].v;
  }

  // dp[i][w] is the maximum value obtainable
  // using the first i items with total weight at
  // most w.
  vector<vector<int64_t>> dp(N + 1, vector<int64_t>(W + 1));

  for (int64_t i = 1; i <= N; ++i) {
    for (int64_t w = 0; w <= W; ++w) {
      // Do not take item i - 1.
      dp[i][w] = dp[i - 1][w];

      // Take item i - 1.
      if (items[i - 1].w <= w) {
        dp[i][w] =
          max(dp[i][w], items[i - 1].v +
                          dp[i - 1][w - items[i - 1].w]);
      }
    }
  }

  cout << dp[N][W] << endl;

  return 0;
}
