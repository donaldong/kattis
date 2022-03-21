#include <bits/stdc++.h>
using namespace std;
array<int,4> DR{1, 1, 0, 1};
array<int,4> DC{0, 1, 1, -1};
int R,C,N;
vector<vector<char>> G;
int count(int r, int c, int d) {
  char t = G[r][c];
  int res = 1;
  while (true) {
    r += DR[d], c += DC[d];
    if (r >= R || c >= C || r < 0 || c < 0) break;
    if (G[r][c] != t) break;
    ++res;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C >> N;
  G.assign(R, vector<char>(C));
  for (auto& row : G) for (auto& c : row) cin >> c;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      if (G[r][c] == 'O') continue;
      for (int d = 0; d < 4; ++d) {
        if (count(r, c, d) != N) continue;
        printf("%s WINS\n", G[r][c] == 'R' ? "RED" : "BLUE");
        return 0;
      }
    }
  }
  printf("NONE\n");
  return 0;
}
