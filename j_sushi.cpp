// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_j
// expected value dp, probability dp
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;

  int64_t one = 0;
  int64_t two = 0;
  int64_t three = 0;

  for (int64_t i = 0; i < N; ++i) {
    int64_t x;
    cin >> x;

    if (x == 1) {
      ++one;
    } else if (x == 2) {
      ++two;
    } else {
      ++three;
    }
  }

  // dp[a][b][c] is the expected number of
  // additional rolls needed when:
  //   a dishes contain 1 piece,
  //   b dishes contain 2 pieces,
  //   c dishes contain 3 pieces.
  vector<vector<vector<double>>> dp(
      N + 1,
      vector<vector<double>>(N + 1, vector<double>(N + 1)));

  // This order guarantees that every state used
  // by the recurrence has already been computed:
  //
  // (a - 1, b, c)     has smaller a
  // (a + 1, b - 1, c) has smaller b
  // (a, b + 1, c - 1) has smaller c
  for (int64_t c = 0; c <= N; ++c) {
    for (int64_t b = 0; b + c <= N; ++b) {
      for (int64_t a = 0; a + b + c <= N; ++a) {
        if (a == 0 && b == 0 && c == 0) {
          continue;
        }

        int64_t nonempty = a + b + c;

        // Expected rolls until we choose a
        // nonempty dish.
        double expected = static_cast<double>(N);

        if (a > 0) {
          expected +=
              static_cast<double>(a) * dp[a - 1][b][c];
        }

        if (b > 0) {
          expected +=
              static_cast<double>(b) * dp[a + 1][b - 1][c];
        }

        if (c > 0) {
          expected +=
              static_cast<double>(c) * dp[a][b + 1][c - 1];
        }

        dp[a][b][c] =
            expected / static_cast<double>(nonempty);
      }
    }
  }

  cout << fixed << setprecision(15) << dp[one][two][three]
       << endl;

  return 0;
}
