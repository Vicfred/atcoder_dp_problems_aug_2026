// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_c
// maximum-value dp
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int64_t N;
  cin >> N;

  struct Day {
    int64_t a, b, c;
  };

  vector<Day> days(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> days[i].a >> days[i].b >> days[i].c;
  }

  // dp[i][activity] is the maximum
  // happiness through day i if we
  // choose that activity on day i.
  vector<vector<int64_t>> dp(N, vector<int64_t>(3));

  dp[0][0] = days[0].a;
  dp[0][1] = days[0].b;
  dp[0][2] = days[0].c;

  for (int64_t i = 1; i < N; ++i) {
    dp[i][0] = days[i].a + max(dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = days[i].b + max(dp[i - 1][0], dp[i - 1][2]);
    dp[i][2] = days[i].c + max(dp[i - 1][0], dp[i - 1][1]);
  }

  cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]})
       << endl;

  return 0;
}
