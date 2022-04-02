/**
 * @date        2022-04-01
 * @tags        grid, shortest path, bfs
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int t, n, m;
  cin >> t >> n >> m;
  vector<string> G(n);
  for (auto& row : G) cin >> row;
  vector<vector<int>> D(n,vector<int>(m, INT_MAX));
  queue<pair<int,int>> q;
  for (int r = 0; r < n; ++r) for (int c = 0; c < m; ++c) {
    if (G[r][c] == 'S') q.emplace(r,c), D[r][c] = 0;
  }
  array<char,4> entry  {'U',   'D',   'L',   'R'};
  array<int,4>  dr     {1,     -1,     0,     0};
  array<int,4>  dc     {0,      0,     1,     -1};
  while (!q.empty())  {
    auto [r,c] = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int r2 = r+dr[i], c2 = c+dc[i];
      if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) continue;
      if (G[r2][c2] == '1') continue;
      if (G[r2][c2] != '0' && entry[i] != G[r2][c2]) continue;
      if (D[r2][c2] <= D[r][c]+1) continue;
      D[r2][c2] = D[r][c]+1, q.emplace(r2,c2);
    }
  }
  int res = INT_MAX;
  for (int r = 0; r < n; ++r) res = min({res, D[r][0], D[r][m-1]});
  for (int c = 0; c < m; ++c) res = min({res, D[0][c], D[n-1][c]});
  if (res > t) cout << "NOT POSSIBLE" << endl;
  else cout << res << endl;
  return 0;
}
