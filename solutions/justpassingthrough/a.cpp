#include <bits/stdc++.h>
using namespace std;
array<int, 3> DR{0, -1, 1};
array<int, 3> DC{-1, -1, -1};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int R,C,N;
  cin >> R >> C >> N;
  vector<vector<int>> G(R, vector<int>(C));
  for (auto& row : G) for (auto& cell : row) cin >> cell;
  using Pass = vector<int>;
  vector<vector<Pass>> dist(R, vector<Pass>(C, Pass(N+1, INT_MAX)));
  for (int r = 0; r < R; ++r) {
    if (G[r][0] < 0) continue;
    dist[r][0][0] = G[r][0];
  }
  auto isPass = [&](int r, int c) {
    if (r==0 || r+1 == R || c == 0 || c+1 == C) return false;
    if (G[r][c] >= G[r-1][c] || G[r][c] >= G[r+1][c]) return false;
    if (G[r][c] <= G[r][c-1] || G[r][c] <= G[r][c+1]) return false;
    return G[r-1][c] >= 0 && G[r+1][c] >= 0 && G[r][c-1] >= 0 && G[r][c+1] >= 0;
  };

  for (int c = 1; c < C; ++c) for (int r = 0; r < R; ++r) {
    if (G[r][c] < 0) continue;
    int pass = isPass(r, c);
    for (int n = pass ; n <= N; ++n) {
      for (int dir = 0; dir < 3; ++dir) {
        int r2 = r+DR[dir], c2 = c+DC[dir];
        if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) continue;
        auto& d= dist[r][c][n];
        auto d2 = dist[r2][c2][n-pass];
        if (G[r2][c2] < 0 || d2 == INT_MAX) continue;
        d = min(d, d2+G[r][c]);
      }
    }
  }

  int res = INT_MAX;
  for (int r = 0; r < R; ++r) {
    res = min(res, dist[r][C-1][N]);
  }
  if (res == INT_MAX) cout << "impossible" << endl;
  else cout << res << endl;
  return 0;
}
