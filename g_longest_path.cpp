// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_g
// dag dp
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int64_t N, M;
  cin >> N >> M;

  vector<vector<int64_t>> graph(N);
  vector<int64_t> indegree(N);

  for (int64_t i = 0; i < M; ++i) {
    int64_t u, v;
    cin >> u >> v;

    u -= 1;
    v -= 1;

    graph[u].push_back(v);
    indegree[v] += 1;
  }

  // Kahn's algorithm starts with all vertices
  // that have no prerequisites, that is, vertices
  // with indegree 0.
  queue<int64_t> q;
  for (int64_t v = 0; v < N; ++v) {
    if (indegree[v] == 0) {
      q.push(v);
    }
  }

  vector<int64_t> topologicalOrder;

  // Build an ordering where every edge u -> v has
  // u before v.
  while (!q.empty()) {
    int64_t u = q.front();
    q.pop();

    topologicalOrder.push_back(u);

    for (int64_t v : graph[u]) {
      indegree[v] -= 1;

      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  // dp[v] is the length of the longest path
  // ending at vertex v.
  vector<int64_t> dp(N);

  // Process vertices in topological order so
  // dp[u] is already final before using the edge
  // u -> v to update dp[v].
  for (int64_t u : topologicalOrder) {
    for (int64_t v : graph[u]) {
      dp[v] = max(dp[v], dp[u] + 1);
    }
  }

  int64_t answer = 0;

  for (int64_t v = 0; v < N; ++v) {
    answer = max(answer, dp[v]);
  }

  cout << answer << endl;

  return 0;
}
