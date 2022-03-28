/**
 * @date        2022-03-27
 * @tags        grid, shortest path, bfs, dfs, dp
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
string I;
int R,C;
vector<string> G;
vector<vector<int>> dist, DP;
vector<int>  DR   { 0,  0,   -1,   1};
vector<int>  DC   {-1,  1,    0,   0};
vector<char> revD {'E', 'W', 'S', 'N'};

int dfs(int r, int c, int p) {
  auto& res = DP[r][c];
  if (res >= 0) return res;
  if (p < 0) return res = 0;
  for (int i = 0; i < 4; ++i) {
    if (I[p] == revD[i]) continue;
    int r2 = r+DR[i], c2 = c+DC[i];
    if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) continue;
    if (dist[r2][c2]+1 != dist[r][c]) continue;
    if (G[r2][c2] == 'S' && p == 0) return res = true;
    if (dfs(r2, c2, p-1)) return res = true;
  }
  return res = false;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  cin >> C >> R;
  G.resize(R);
  for (auto& row : G) cin >> row;
  cin >> I;
  dist.assign(R, vector<int>(C, INT_MAX));
  DP.assign(R, vector<int>(C, -1));

  queue<pair<int,int>> q; // bfs
  for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) if (G[i][j]=='S') {
    dist[i][j] = 0, q.emplace(i,j);
  }
  while (!q.empty()) {
    auto [r,c] = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int r2 = r+DR[i], c2 = c+DC[i];
      if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) continue;
      if (dist[r2][c2] <= dist[r][c]+1 || G[r2][c2] != '.') continue;
      dist[r2][c2] = dist[r][c]+1, q.emplace(r2, c2);
    }
  }
  for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {//dfs
    if (dist[i][j] != I.size()) continue;
    if (dfs(i, j, I.size()-1)) G[i][j] = '!';
  }

  for (auto& row : G) cout << row << endl;
  return 0;
}
