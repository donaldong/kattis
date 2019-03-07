#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;
using v2b = vector<vb>;
using pq = priority_queue<tuple<int, int, int>>;

int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int w, R, C, r, c, nr, nc;
  cin >> R >> C;
  r = R, c = C;
  v2i G(r, vi(c)); v2b vis(r, vb(c, false));
  for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j)
    cin >> G[i][j];
  pq Q;
  int res = 1e9;
  for (int i = 0; i < r; ++i) Q.emplace(-G[i][0], i, 0);
  while (!Q.empty()) {
    tie(w, r, c) = Q.top(), Q.pop();
    if (vis[r][c]) continue;
    vis[r][c] = true;
    w *= -1;
    if (c + 1 == C) {
      res = min(res, w);
      continue;
    }
    for (int i = 0; i < 4; ++i) {
      nr = r + DR[i], nc = c + DC[i];
      if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
      if (vis[nr][nc]) continue;
      Q.emplace(-max(w, G[nr][nc]), nr, nc);
    }
  }
  printf("%d\n", res);
  return 0;
}
