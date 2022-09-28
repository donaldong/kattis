/**
 * @date        2022-09-27
 * @tags        graph, probability
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
// - Find number of nodes in each connected piece in the graph (k).
// - k*(k-1)/2 pairs can earn points. ans = # pairs can earn points / # total pairs 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n);
  vector<bool> vis(n, false);
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v), graph[v].push_back(u);
  }

  function<int(int)> dfs = [&](int u) {
    if (vis[u]) return 0;
    vis[u] = true;
    int res = 1;
    for (auto v : graph[u]) {
      res += dfs(v);
    }
    return res;
  };

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    long long k = dfs(i);
    res += k*(k-1)/2;
  }
  cout << setprecision(7) << (double)res/((long long)n*(n-1)/2) << endl;
  return 0;
}
