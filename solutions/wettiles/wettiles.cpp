#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
int X, Y, T, L, W;
v2i G;
queue<tuple<int, int>> Q;

void norm(int &d) {
  if (d > 0) d = 1;
  else if (d < 0) d = -1;
}

int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

int solve() {
  int r, c, r1, c1, res = 0;
  while (!Q.empty()) {
    tie(r, c) = Q.front(), Q.pop();
    ++res;
    for (int i = 0; i < 4; ++i) {
      r1 = r + DR[i], c1 = c + DC[i];
      if (r1 < 0 || r1 >= Y || c1 < 0 || c1 >= X) continue;
      if (G[r][c] + 1 >= G[r1][c1]) continue;
      G[r1][c1] = G[r][c] + 1;
      Q.emplace(r1, c1);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int x, y, x1, y1, dx, dy;
  while (cin >> X >> Y >> T >> L >> W) {
    if (X < 0) break;
    G.assign(Y, vi(X, T + 1));
    while (L--) {
      cin >> x >> y;
      --y, --x;
      G[y][x] = 1;
      Q.emplace(y, x);
    }
    while (W--) {
      cin >> x >> y >> x1 >> y1;
      --x, --y, --x1, --y1;
      dx = x1 - x, dy = y1 - y;
      norm(dx), norm(dy);
      while (true) {
        G[y][x] = 0;
        if (y == y1 && x == x1) break;
        y += dy, x += dx;
      }
    }
    printf("%d\n", solve());
  }
  return 0;
}
