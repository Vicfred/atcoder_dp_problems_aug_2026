// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_b
// minimum-cost dp
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int main() {
  int64_t N, K;
  cin >> N >> K;

  vector<int64_t> h(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> h[i];
  }

  // dp[i] is the minimum cost needed to reach
  // stone i.
  vector<int64_t> dp(N, numeric_limits<int64_t>::max() / 4);
  dp[0] = 0;

  for (int64_t i = 1; i < N; ++i) {
    for (int64_t k = 1; k <= min(K, i); ++k) {
      dp[i] = min(dp[i], dp[i - k] + abs(h[i] - h[i - k]));
    }
  }

  cout << dp[N - 1] << endl;

  return 0;
}
