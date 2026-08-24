// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_y
// grid path counting dp, combinatorics
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int64_t modPow(int64_t base, int64_t exponent,
               int64_t mod) {
  int64_t result = 1;

  while (exponent > 0) {
    if (exponent % 2 == 1) {
      result = result * base % mod;
    }

    base = base * base % mod;
    exponent /= 2;
  }

  return result;
}

int64_t combinations(
  int64_t n, int64_t k, const vector<int64_t> &factorial,
  const vector<int64_t> &inverseFactorial, int64_t mod) {
  if (k < 0 || k > n) {
    return 0;
  }

  return factorial[n] * inverseFactorial[k] % mod *
         inverseFactorial[n - k] % mod;
}

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t H, W, N;
  cin >> H >> W >> N;

  struct Point {
    int64_t row, col;
  };

  vector<Point> points(N + 1);

  for (int64_t i = 0; i < N; ++i) {
    cin >> points[i].row >> points[i].col;
  }

  // Treat the destination as one final special point.
  points[N] = {H, W};

  // If point j can appear before point i on a right/down
  // path, this ordering guarantees that j appears earlier.
  sort(points.begin(), points.end(),
       [](const Point &a, const Point &b) {
         if (a.row != b.row) {
           return a.row < b.row;
         }

         return a.col < b.col;
       });

  // A path can make at most H + W - 2 moves, so factorials
  // up to H + W are sufficient for every binomial
  // coefficient.
  int64_t maxFactorial = H + W;

  vector<int64_t> factorial(maxFactorial + 1);
  vector<int64_t> inverseFactorial(maxFactorial + 1);

  factorial[0] = 1;
  for (int64_t i = 1; i <= maxFactorial; ++i) {
    factorial[i] = factorial[i - 1] * i % MOD;
  }

  // MOD is prime, so x^(MOD - 2) is the modular inverse of
  // x.
  inverseFactorial[maxFactorial] =
    modPow(factorial[maxFactorial], MOD - 2, MOD);

  for (int64_t i = maxFactorial; i > 0; --i) {
    inverseFactorial[i - 1] = inverseFactorial[i] * i % MOD;
  }

  // dp[i] is the number of paths from (1, 1) to points[i]
  // that do not pass through any earlier wall.
  //
  // For a wall, these are the paths for which it is the
  // first wall encountered. For the destination, these are
  // exactly the paths that avoid every wall.
  vector<int64_t> dp(N + 1);

  for (int64_t i = 0; i <= N; ++i) {
    int64_t row = points[i].row;
    int64_t col = points[i].col;

    // Start with every monotone path from (1, 1) to this
    // point.
    dp[i] = combinations(row + col - 2, row - 1, factorial,
                         inverseFactorial, MOD);

    // Remove paths whose first wall encountered was an
    // earlier wall j and which then continued to point i.
    for (int64_t j = 0; j < i; ++j) {
      if (points[j].col > col) {
        continue;
      }

      int64_t down = row - points[j].row;
      int64_t right = col - points[j].col;

      int64_t pathsFromJ =
        combinations(down + right, down, factorial,
                     inverseFactorial, MOD);

      dp[i] -= dp[j] * pathsFromJ % MOD;

      if (dp[i] < 0) {
        dp[i] += MOD;
      }
    }
  }

  // The destination was added as the final special point.
  cout << dp[N] << endl;

  return 0;
}
