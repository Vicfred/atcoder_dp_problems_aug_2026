// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_q
// weighted LIS dp, prefix maximum, fenwick tree
// O(N log N)
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct FenwickMax {
  int64_t n;
  vector<int64_t> tree;

  FenwickMax(int64_t n) : n(n), tree(n + 1, 0) {
  }

  // Record that position index can achieve at least value.
  // Each Fenwick node stores the maximum over its interval.
  void update(int64_t index, int64_t value) {
    while (index <= n) {
      tree[index] = max(tree[index], value);
      index += index & -index;
    }
  }

  // Return the maximum value over positions [1, index].
  int64_t query(int64_t index) const {
    int64_t result = 0;

    while (index > 0) {
      result = max(result, tree[index]);
      index -= index & -index;
    }

    return result;
  }
};

int main() {
  int64_t N;
  cin >> N;

  struct Flower {
    int64_t h, a;
  };

  vector<Flower> flowers(N);

  for (int64_t i = 0; i < N; ++i) {
    cin >> flowers[i].h;
  }

  for (int64_t i = 0; i < N; ++i) {
    cin >> flowers[i].a;
  }

  // dp[i] is the maximum total beauty of an increasing
  // subsequence whose last flower is i.
  vector<int64_t> dp(N + 1);

  // Fenwick positions represent heights. The value stored
  // for a height is the best dp value ending at that
  // height.
  FenwickMax fenwick(N);

  for (int64_t i = 1; i <= N; ++i) {
    int64_t h = flowers[i - 1].h;
    int64_t a = flowers[i - 1].a;

    // All values currently in the tree come from earlier
    // flowers, so j < i is already guaranteed.
    //
    // Querying heights [1, h - 1] finds the best previous
    // subsequence whose last height is strictly smaller.
    int64_t best = fenwick.query(h - 1);

    // If there is no smaller previous height, best is 0,
    // so this also covers the subsequence containing only
    // i.
    dp[i] = a + best;

    // Make this subsequence available to later flowers,
    // indexed by the height of its last flower.
    fenwick.update(h, dp[i]);
  }

  // The optimal increasing subsequence may end at any
  // flower.
  int64_t answer = 0;
  for (int64_t i = 1; i <= N; ++i) {
    answer = max(answer, dp[i]);
  }

  cout << answer << endl;

  return 0;
}
