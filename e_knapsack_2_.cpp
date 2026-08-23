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

  const int64_t INF =
      numeric_limits<int64_t>::max() / 4;

  // dp[v] is the minimum weight needed to obtain
  // exactly value v using the items considered so
  // far.
  vector<int64_t> dp(totalValue + 1, INF);

  // Value 0 can always be obtained by taking no
  // items.
  dp[0] = 0;

  for (const auto &item : items) {
    // Iterate backwards so dp[v - item.v] still
    // represents a state before considering this
    // item. This prevents using the same item
    // more than once.
    for (int64_t v = totalValue; v >= item.v;
         --v) {
      dp[v] = min(dp[v], item.w + dp[v - item.v]);
    }
  }

  int64_t answer = 0;

  // Find the greatest value whose minimum
  // required weight does not exceed the knapsack
  // capacity.
  for (int64_t v = 0; v <= totalValue; ++v) {
    if (dp[v] <= W) {
      answer = v;
    }
  }

  cout << answer << endl;

  return 0;
}
