// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_t
// permutation dp, rank dp, prefix sums
// O(N^2)
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t N;
  cin >> N;

  string s;
  cin >> s;

  // previous[j] is the number of valid permutations of the
  // current length i - 1 whose last element has rank j.
  //
  // For length 1, the only permutation has one element and
  // its last element has rank 0.
  vector<int64_t> previous(N);
  previous[0] = 1;

  for (int64_t i = 2; i <= N; ++i) {
    vector<int64_t> current(N);
    vector<int64_t> prefix(i);

    // prefix[x] = sum of previous[0..x - 1].
    // This lets us answer the naive O(N) range sums in
    // O(1).
    for (int64_t x = 0; x <= i - 2; ++x) {
      prefix[x + 1] = prefix[x] + previous[x];
      prefix[x + 1] %= MOD;
    }

    for (int64_t j = 0; j < i; ++j) {
      if (s[i - 2] == '<') {
        // The previous last rank must be smaller than j.
        //
        // current[j] =
        //   previous[0] + previous[1] + ... + previous[j -
        //   1]
        current[j] = prefix[j];
      } else {
        // The previous last rank must be at least j.
        //
        // current[j] =
        //   previous[j] + previous[j + 1] + ... +
        //   previous[i - 2]
        current[j] =
          (prefix[i - 1] - prefix[j] + MOD) % MOD;
      }
    }

    previous = current;
  }

  // For N = 1, previous already represents length 1.
  int64_t answer = 0;
  for (int64_t j = 0; j < N; ++j) {
    answer += previous[j];
    answer %= MOD;
  }

  cout << answer << endl;

  return 0;
}
