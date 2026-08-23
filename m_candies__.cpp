// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_m
// counting dp with sliding window
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t N, K;
  cin >> N >> K;

  vector<int64_t> a(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> a[i];
  }

  // previous[k] is the number of ways to
  // distribute exactly k candies among the
  // children processed so far.
  vector<int64_t> previous(K + 1);
  vector<int64_t> current(K + 1);

  previous[0] = 1;

  for (int64_t i = 0; i < N; ++i) {
    // window is the sum of the valid previous
    // states:
    //
    // previous[max(0, k - a[i]) ... k]
    int64_t window = 0;

    for (int64_t k = 0; k <= K; ++k) {
      // previous[k] enters the right side of the
      // window.
      window += previous[k];
      window %= MOD;

      // This state would correspond to giving
      // more than a[i] candies to the current
      // child, so it leaves.
      int64_t leaving = k - a[i] - 1;

      if (leaving >= 0) {
        window -= previous[leaving];

        if (window < 0) {
          window += MOD;
        }
      }

      current[k] = window;
    }

    swap(previous, current);
  }

  cout << previous[K] << endl;

  return 0;
}
