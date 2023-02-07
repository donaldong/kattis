/**
 * @date        2023-02-06
 * @tags        graph, dfs, bfs, flood fill
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int r, c;
  cin >> c >> r;
  vector<vector<int>> G(r, vector<int>(c));
  vector<vector<bool>> vis(r, vector<bool>(c, false));
  for (auto& row : G) for (auto& cell : row) cin >> cell;
  vector<int> dir{0,-1,0,1,0};
  int res = 0, sink;
  function<int(int,int)> dfs = [&](int i, int j) {
    if (vis[i][j]) return 0;
    vis[i][j] = true;
    int res = 1;
    for (int d = 0; d < 4; ++d) {
      int i2 = i+dir[d], j2 = j+dir[d+1];
      if (i2 < 0 || i2 >= r || j2 < 0 || j2 >= c) continue;
      if (G[i2][j2] < G[i][j]) sink = false;
      if (G[i2][j2] == G[i][j]) res += dfs(i2, j2);
    }
    return sink ? res : 0;
  };
  for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
    sink = true;
    res += dfs(i, j);
  }
  cout << res << endl;
  return 0;
}
