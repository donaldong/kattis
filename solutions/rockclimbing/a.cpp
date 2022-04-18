/**
 * @date        2022-04-12
 * @tags        grid, shortest path, negative weights
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int R,C;
  cin >> R >> C;
  char c;
  for (int i = 0; i < C; ++i) cin >> c;
  vector<vector<int>> G(R, vector<int>(C));
  vector<vector<int>> dist(R, vector<int>(C, INT_MAX));
  for (auto& row : G) for (auto& cell  : row) {
    cin >> cell;
  }
  queue<pair<int,int>> q;
  set<pair<int,int>> E;
  array<int,4> DR{0,0,-1,1};
  array<int,4> DC{-1,1,0,0};

  for (int i = 0; i < C; ++i) {
    int d = dist[R-1][i] = G[R-1][i];
    if (d < 0) E.emplace(R-1, i);
  }
  for (int r = 0; r+1 < R; ++r) for (int c = 0; c < C; ++c) {
    if (G[r][c] > 0) continue;
    for (int i = 0; i < 4; ++i) {
      int r2 = r + DR[i], c2 = c + DC[i];
      if (r2 < 0 || r2 >= R || c2 < 0 ||  c2 >= C) continue;
      if (G[r][c]+G[r2][c2] < 0) E.emplace(r, c);
    }
  }
  for (int i = 0; i < C; ++i) {
    if (E.count(make_pair(R-1, i))) continue;
    q.emplace(R-1, i);
  }
  while (!q.empty()) {
    auto [r,c] = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int r2 = r + DR[i], c2 = c + DC[i];
      if (r2 < 0 || r2 >= R || c2 < 0 ||  c2 >= C) continue;
      if (E.count(make_pair(r2,c2))) {
        dist[r2][c2] = min(dist[r][c], dist[r2][c2]);
        continue;
      }
      int cost = G[r2][c2];
      if (dist[r2][c2] <= dist[r][c]+cost) continue;
      dist[r2][c2] = dist[r][c]+cost;
      q.emplace(r2,c2);
    }
  }
  int res = INT_MAX;
  for (int v : dist[0]) {
    if (v == INT_MAX) continue;
    res = min(res, v);
  }
  for (auto [r,c] : E) res = min(res, dist[r][c]);
  cout << (res == INT_MAX ? 0 : max(res, 0)) << endl;
  return 0;
}
