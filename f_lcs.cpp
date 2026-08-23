// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_f
// longest common subsequence
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s, t;
  cin >> s;
  cin >> t;

  int64_t n = static_cast<int64_t>(s.size());
  int64_t m = static_cast<int64_t>(t.size());

  // dp[i][j] is the length of the longest common
  // subsequence between the prefixes s[0..i - 1]
  // and t[0..j - 1].
  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1));

  for (int64_t i = 1; i <= n; ++i) {
    for (int64_t j = 1; j <= m; ++j) {
      if (s[i - 1] == t[j - 1]) {
        // Matching characters can extend the LCS
        // of the prefixes that end immediately
        // before them.
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        // Otherwise, skip one character from
        // either s or t.
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  // Reconstruct one LCS by walking backwards
  // through the DP table.
  int64_t i = n;
  int64_t j = m;
  string answer;

  while (i > 0 && j > 0) {
    if (s[i - 1] == t[j - 1]) {
      // This matching character belongs to the
      // reconstructed LCS.
      answer.push_back(s[i - 1]);
      i -= 1;
      j -= 1;
    } else if (dp[i - 1][j] >= dp[i][j - 1]) {
      // The optimal value came from ignoring s[i
      // - 1].
      i -= 1;
    } else {
      // The optimal value came from ignoring t[j
      // - 1].
      j -= 1;
    }
  }

  // Reconstruction proceeds from the end of the
  // strings backwards.
  reverse(answer.begin(), answer.end());

  cout << answer << endl;

  return 0;
}
