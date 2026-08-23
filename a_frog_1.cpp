// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_a
// minimum-cost dp
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;

  vector<int64_t> h(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> h[i];
  }

  // dp[i] is the minimum cost needed to reach
  // stone i.
  vector<int64_t> dp(N);
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int64_t i = 2; i < N; ++i) {
    dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                dp[i - 2] + abs(h[i] - h[i - 2]));
  }

  cout << dp[N - 1] << endl;

  return 0;
}
