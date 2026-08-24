// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_q
// weighted LIS dp, range sum, fenwick, segment tree
// O(N^2) TLE
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

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

  // A subsequence containing only flower i is always valid.
  for (int64_t i = 1; i <= N; ++i) {
    dp[i] = flowers[i - 1].a;
  }

  for (int64_t i = 2; i <= N; ++i) {
    for (int64_t j = 1; j < i; ++j) {
      // Flower i can follow j only if its height is larger.
      if (flowers[j - 1].h < flowers[i - 1].h) {
        dp[i] = max(dp[i], flowers[i - 1].a + dp[j]);
      }
    }
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
