// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_k
// game dp
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N, K;
  cin >> N >> K;

  vector<int64_t> a(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> a[i];
  }

  // dp[k] is true if the player whose turn it is
  // can force a win when there are exactly k
  // stones remaining.
  vector<char> dp(K + 1);

  // With no stones left, the current player has
  // no legal move and therefore loses.
  dp[0] = false;

  for (int64_t k = 1; k <= K; ++k) {
    for (int64_t x : a) {
      // A state is winning if we can move to at
      // least one losing state for the opponent.
      if (x <= k && !dp[k - x]) {
        dp[k] = true;
        break;
      }
    }
  }

  if (dp[K]) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }

  return 0;
}
