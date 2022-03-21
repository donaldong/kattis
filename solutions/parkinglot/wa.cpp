#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int R,C;
  cin >> R >> C;
  vector<string> G(R);
  for (auto& row : G) cin >> row;

  vector<vector<int>> prefix(R+1, vector<int>(C+1, 0));
  for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
    if (G[r][c] == '#') prefix[r][c] = 1;
  }
  for (int r = R-1; r >= 0; --r) for (int c = C-1; c >= 0; --c) {
    prefix[r][c] += prefix[r][c+1]+prefix[r+1][c]-prefix[r+1][c+1];
  }
#ifdef DEBUG
  for (int r = 0; r <= R; ++r) {
    for (int c = 0; c <= C; ++c) printf("%d ", prefix[r][c]);
    printf("\n");
  }
#endif

  auto calcDist = [&](int r1, int c1, int r2, int c2) -> double {
    if (r1 == r2) return abs(c2-c1);
    if (c1 == c2) return abs(r2-r1);
    if (r2 < r1) swap(r1, r2);
    if (c2 < c1) swap(c1, c2);
    int k = prefix[r1][c1] - prefix[r1][c2] - prefix[r2][c1] + prefix[r2][c2];
    if (k) return -1.0;
    double dr = r1-r2, dc = c1-c2;
    return sqrt(dr*dr+dc*dc);
  };

  vector<vector<double>> dist(R+1, vector<double>(C+1, DBL_MAX));
  dist[0][0] = 0.0;
  for (int r1 = 0; r1 <= R; ++r1) for (int c1 = 0; c1 <= C; ++c1) {
    for (int r2 = 0; r2 <= R; ++r2) for (int c2 = 0; c2 <= C; ++c2) {
      if (r1 == r2 && c1 == c2) continue;
      auto w = calcDist(r1, c1, r2, c2);
      if (w < 0) continue;
      auto d = dist[r1][c1]+w;
      if (d > dist[r2][c2]) continue;
      dist[r2][c2] = d;
    }
  }
  printf("%.12lf\n", dist[R][C]);
  return 0;
}
