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

  // dp[w] is the maximum value obtainable with
  // capacity at most w.
  vector<int64_t> dp(W + 1);

  for (const auto &item : items) {
    // Iterate backwards so dp[w - item.w] still
    // represents a state before considering this
    // item. This prevents using an item twice.
    for (int64_t w = W; w >= item.w; --w) {
      dp[w] = max(dp[w], item.v + dp[w - item.w]);
    }
  }

  cout << dp[W] << endl;

  return 0;
}
