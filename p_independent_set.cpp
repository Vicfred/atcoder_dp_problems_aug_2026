// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_p
// tree dp
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int64_t v, int64_t parent,
         const vector<vector<int64_t>> &tree,
         vector<vector<int64_t>> &dp, int64_t mod) {
  // dp[v][0]: valid colorings of v's subtree when v is
  // white. dp[v][1]: valid colorings of v's subtree when v
  // is black.
  //
  // A leaf has exactly one coloring for each choice of its
  // color.
  dp[v][0] = 1;
  dp[v][1] = 1;

  for (int64_t u : tree[v]) {
    if (u == parent) {
      continue;
    }

    // Compute the child's subtree before using its DP
    // values.
    dfs(u, v, tree, dp, mod);

    // If v is white, u may be either white or black.
    // Different child subtrees are independent, so their
    // numbers of valid colorings are multiplied.
    dp[v][0] *= dp[u][0] + dp[u][1];
    dp[v][0] %= mod;

    // If v is black, every child must be white.
    dp[v][1] *= dp[u][0];
    dp[v][1] %= mod;
  }
}

int main() {
  const int64_t MOD = 1'000'000'007;

  int64_t N;
  cin >> N;

  vector<vector<int64_t>> tree(N);

  for (int64_t i = 0; i < N - 1; ++i) {
    int64_t u, v;
    cin >> u >> v;
    u -= 1;
    v -= 1;

    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  vector<vector<int64_t>> dp(N, vector<int64_t>(2));

  // Any vertex can be chosen as the root.
  // DFS gives us the postorder needed for subtree DP.
  dfs(0, -1, tree, dp, MOD);

  // The root itself may be either white or black.
  cout << (dp[0][0] + dp[0][1]) % MOD << endl;

  return 0;
}
