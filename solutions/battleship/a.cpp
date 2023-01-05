/**
 * @date        2023-01-05
 * @tags        simulation, implementation
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int t,w,h,n,r,c;
  cin >> t;
  while (t--) {
    cin >> w >> h >> n;
    vector<vector<string>> G(2, vector<string>(h));
    vector<int> K{0, 0}; // num ships
    for (int i = 0; i < 2; ++i) {
      auto& grid = G[i];
      for (auto& row : grid) {
        cin >> row;
        for (char c : row) if (c == '#') ++K[i];
      }
      reverse(grid.begin(), grid.end());
    }
    while (n>0 && K[0] && K[1]) {
      for (int turn = 0; turn < 2; ++turn) {
        while (n-->0) {
          cin >> c >> r;
          if (G[1-turn][r][c] == '#') {
            G[1-turn][r][c] = '_';
            --K[1-turn];
            if (K[1-turn] == 0) break;
          } else break;
        }
      }
    }
    while (n-->0) cin >> c >> r;
    if (K[0]+K[1] == 0 || (K[0]&&K[1])) cout << "draw\n";
    else {
      if (K[1]) cout << "player two wins\n";
      else cout << "player one wins\n";
    }
  }
  return 0;
}
