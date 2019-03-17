#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;

int NEG_INF = -1e9;
v2i G(5, vi(9, 0));
int DR[] = {-1, -1, 1, 1, 0, 0};
int DC[] = {1, -1, 1, -1, 2, -2};

bool oob(int nr, int nc) {
  nc += nr - 4;
  if (nc % 2) return true;
  nc /= 2;
  return nr < 0 || nr >= 5 || nc < 0 || nc > nr;
}

int solve() {
  int nr, nc, nnr, nnc, score, max_diff = NEG_INF;
  int A, B;
  for (int r = 0; r < 5; ++r) {
    for (int c = 0; c < 9; ++c) {
      if (!G[r][c]) continue;
      for (int i = 0; i < 6; ++i) {
        nr = r + DR[i], nc = c + DC[i];
        if (oob(nr, nc) || !G[nr][nc]) continue;
        nnr = nr + DR[i], nnc = nc + DC[i];
        if (oob(nnr, nnc) || G[nnr][nnc]) continue;
        A = G[r][c], B = G[nr][nc];
        score = A * B;
        G[nr][nc] = G[r][c] = 0;
        G[nnr][nnc] = A;
        max_diff = max(score - solve(), max_diff);
        G[r][c] = A, G[nr][nc] = B, G[nnr][nnc] = 0;
      }
    }
  }
  return max_diff == NEG_INF? 0 : max_diff;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, r, c;
  for (r = 0; r < 5; ++r) {
    for (c = 0; c <= r; ++c) {
      cin >> G[r][2 * c + 4 - r];
    }
  }
  printf("%d\n", solve());
  return 0;
}
