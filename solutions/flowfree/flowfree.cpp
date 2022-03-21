#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;
char K[] = {'R', 'G', 'B', 'Y'};
int R[] = {-1, -1, -1, -1}, C[] = {-1, -1, -1, -1};
int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};
int max_col;
vs G(4);
int n;

bool solve(int k, int r, int c) {
  for (int i = 0; i < 4; ++i) {
    int r2 = r + DR[i], c2 = c + DC[i];
    if (!(0 <= r2 && r2 < 4 && 0 <= c2 && c2 < 4)) continue;
    if ((r2 != R[k] || c2 != C[k]) && G[r2][c2] == K[k]) {
      if (k == max_col) if (n == 16) return true;
      if (solve(k + 1, R[k + 1], C[k + 1])) return true;
      continue;
    }
    if (G[r2][c2] != 'W') continue;
    G[r2][c2] = 'X';
    ++n;
#ifdef DEBUG
    printf("%c: [%d %d]\n", K[k], r2, c2);
    for (int i = 0; i < 4; ++i) printf("%s\n", G[i].c_str());
    puts("");
#endif
    if (solve(k, r2, c2)) return true;
    G[r2][c2] = 'W';
    --n;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  n = 0;
  for (int i = 0; i < 4; ++i) cin >> G[i];
  for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) {
    if (G[i][j] == 'R') ++n, R[0] = i, C[0] = j;
    else if (G[i][j] == 'G') ++n, R[1] = i, C[1] = j;
    else if (G[i][j] == 'B') ++n, R[2] = i, C[2] = j;
    else if (G[i][j] == 'Y') ++n, R[3] = i, C[3] = j;
  }
  max_col = R[3] == -1 ? 2 : 3;

  printf("%s\n", solve(0, R[0], C[0]) ? "solvable" : "not solvable");
  return 0;
}
