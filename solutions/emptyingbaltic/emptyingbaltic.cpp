#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using ti3 = tuple<int, int, int>;
using ll = long long;

vi DIRS = {-1, 0, 1};
int H, W;

bool in_range(int r, int c) {
  return 0 <= r && r < H && 0 <= c && c < W;
}

void debug(v2i &G) {
  cout << endl;
  for (auto &row : G) {
    for (auto &cell : row) cout << cell << " ";
    cout << endl;
  }
}

ll solve(v2i &G, int r, int c) {
  int w, nr, nc;
  priority_queue<ti3> Q;
  v2i V(H, vi(W, 0));
  w = G[r][c];
  Q.emplace(-w, r, c);
  V[r][c] = 1;
  while (!Q.empty()) {
    tie(w, r, c) = Q.top(); Q.pop();
    w *= -1;
    for (int dr : DIRS) for (int dc : DIRS) {
      if (!dr && !dc) continue;
      nr = r + dr, nc = c + dc;
      if (!in_range(nr, nc)) continue;
      if (!V[nr][nc]) {
        V[nr][nc] = 1;
        if (w >= G[nr][nc]) {
          G[nr][nc] = w;
          Q.emplace(-w, nr, nc);
        } else {
          Q.emplace(-G[nr][nc], nr, nc);
        }
      } 
    }
  }
  ll res = 0;
  for (auto &row : G) for (auto cell : row) res += cell;
  return -res;
}

int main() {
  int x, y;
  cin >> H >> W;
  v2i G(H, vi(W));
  for (auto &row : G) for (auto &cell : row) {
    cin >> cell;
    cell = min(cell, 0);
  }
  cin >> x >> y;
  cout << solve(G, x - 1, y - 1) << endl;
  return 0;
}
