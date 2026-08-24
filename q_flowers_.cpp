// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_q
// weighted LIS dp, range maximum, segment tree
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct SegmentTreeMax {
  int64_t size;
  vector<int64_t> tree;

  SegmentTreeMax(int64_t n) {
    size = 1;
    while (size < n) {
      size *= 2;
    }

    tree.assign(2 * size, 0);
  }

  // Set position index to at least value.
  void update(int64_t index, int64_t value) {
    index += size;

    tree[index] = max(tree[index], value);

    while (index > 1) {
      index /= 2;
      tree[index] =
        max(tree[2 * index], tree[2 * index + 1]);
    }
  }

  // Maximum over the half-open interval [left, right).
  int64_t query(int64_t left, int64_t right) const {
    left += size;
    right += size;

    int64_t result = 0;

    while (left < right) {
      if (left % 2 == 1) {
        result = max(result, tree[left]);
        ++left;
      }

      if (right % 2 == 1) {
        --right;
        result = max(result, tree[right]);
      }

      left /= 2;
      right /= 2;
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
  vector<int64_t> dp(N);

  SegmentTreeMax segmentTree(N);

  for (int64_t i = 0; i < N; ++i) {
    // Heights are 1-based, while the segment tree positions
    // are 0-based. Heights smaller than h therefore occupy
    // positions [0, h - 1).
    int64_t best = segmentTree.query(0, flowers[i].h - 1);

    dp[i] = flowers[i].a + best;

    // Position h - 1 represents height h.
    segmentTree.update(flowers[i].h - 1, dp[i]);
  }

  int64_t answer = 0;
  for (int64_t value : dp) {
    answer = max(answer, value);
  }

  cout << answer << endl;

  return 0;
}
