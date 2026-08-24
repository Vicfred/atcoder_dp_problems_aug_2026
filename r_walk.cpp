// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_r
// counting dp, matrix exponentiation
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int64_t>>;

Matrix multiply(const Matrix &a, const Matrix &b,
                int64_t mod) {
  int64_t n = static_cast<int64_t>(a.size());
  Matrix result(n, vector<int64_t>(n));

  // result[i][j] counts all ways obtained by choosing an
  // intermediate vertex k:
  //
  // i -- represented by a --> k
  // k -- represented by b --> j
  //
  // This is exactly the transition used when concatenating
  // two groups of edges in the walk.
  for (int64_t i = 0; i < n; ++i) {
    for (int64_t k = 0; k < n; ++k) {
      for (int64_t j = 0; j < n; ++j) {
        result[i][j] += a[i][k] * b[k][j];
        result[i][j] %= mod;
      }
    }
  }

  return result;
}

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t N, K;
  cin >> N >> K;

  Matrix adjacency(N, vector<int64_t>(N));

  for (int64_t i = 0; i < N; ++i) {
    for (int64_t j = 0; j < N; ++j) {
      cin >> adjacency[i][j];
    }
  }

  // (A^k)[i][j] is the number of walks of exactly k edges
  // from vertex i to vertex j.
  //
  // The identity matrix represents walks of length 0:
  // there is one way to stay at the same vertex without
  // traversing any edge.
  Matrix result(N, vector<int64_t>(N));
  for (int64_t i = 0; i < N; ++i) {
    result[i][i] = 1;
  }

  Matrix base = adjacency;

  // Binary exponentiation computes A^K in O(log K) matrix
  // multiplications instead of applying the DP transition
  // once for every one of the K edges.
  //
  // base successively represents A, A^2, A^4, A^8, ...
  while (K > 0) {
    if (K % 2 == 1) {
      result = multiply(result, base, MOD);
    }

    base = multiply(base, base, MOD);
    K /= 2;
  }

  // result[i][j] now counts length-K walks from i to j.
  // Any vertex may be the start or end, so sum all entries.
  int64_t answer = 0;

  for (int64_t i = 0; i < N; ++i) {
    for (int64_t j = 0; j < N; ++j) {
      answer += result[i][j];
      answer %= MOD;
    }
  }

  cout << answer << endl;

  return 0;
}
