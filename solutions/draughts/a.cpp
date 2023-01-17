/**
 * @date        2023-01-16
 * @tags        graph, dfs, backtracking, brute force
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int tc;
  cin >> tc;
  vector<int> DR{-1, -1, 1, 1};
  vector<int> DC{-1,  1,-1, 1};
  auto step = [&](int d, int r, int c) -> tuple<bool, int, int> {
    r += DR[d], c += DC[d];
    return {r >= 0 && r < 10 && c >= 0 && c < 10, r, c};
  };
  while (tc--) {
    vector<string> G(10);
    for (auto& row : G) cin >> row;
    function<int(int,int)> dfs = [&](int i, int j) {
      int res = 0;
      for (int d = 0; d < 4; ++d) {
        auto [f2, i2, j2] = step(d, i, j);
        if (!f2 || G[i2][j2] != 'B') continue;
        auto [f3, i3, j3] = step(d, i2, j2);
        if (!f3 || G[i3][j3] != '#') continue;
        G[i2][j2] = '#';
        res = max(res, dfs(i3, j3)+1);
        G[i2][j2] = 'B';
      }
      return res;
    };
    int res = 0;
    for (int i = 0; i < 10; ++i) for (int j = 0; j < 10; ++j) {
      if (G[i][j] == 'W') {
        G[i][j] = '#';
        res = max(res, dfs(i, j));
        G[i][j] = 'W';
      }
    }
    cout << res << '\n';
  }
  return 0;
}
