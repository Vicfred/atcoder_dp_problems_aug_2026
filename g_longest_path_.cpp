// vicfred
// https://atcoder.jp/contests/dp/tasks/dp_g
// dag dp
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

void dfs(int64_t u, const vector<vector<int64_t>> &graph,
         vector<char> &visited, vector<int64_t> &order) {
  visited[u] = true;

  for (int64_t v : graph[u]) {
    if (!visited[v]) {
      dfs(v, graph, visited, order);
    }
  }

  // Add u only after all vertices reachable
  // directly from it have been processed. This
  // produces reverse topological order.
  order.push_back(u);
}

int main() {
  int64_t N, M;
  cin >> N >> M;

  vector<vector<int64_t>> graph(N);

  for (int64_t i = 0; i < M; ++i) {
    int64_t u, v;
    cin >> u >> v;

    u -= 1;
    v -= 1;

    graph[u].push_back(v);
  }

  vector<char> visited(N);
  vector<int64_t> topologicalOrder;

  // Run DFS from every unvisited vertex because
  // the DAG does not need to be connected.
  for (int64_t v = 0; v < N; ++v) {
    if (!visited[v]) {
      dfs(v, graph, visited, topologicalOrder);
    }
  }

  // DFS postorder gives the reverse of a
  // topological ordering.
  reverse(topologicalOrder.begin(), topologicalOrder.end());

  // dp[v] is the length of the longest path
  // ending at vertex v.
  vector<int64_t> dp(N);

  // In topological order, every predecessor u of
  // v is processed before v, so each edge u -> v
  // can extend a path ending at u.
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
