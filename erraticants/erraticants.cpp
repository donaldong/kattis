#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<v2i> v3i;

int DR[] = {-1, 0, 1, 0};
int DC[] = {0, 1, 0, -1};
int rev[] = {2, 3, 0, 1};

int bfs(v3i &G, int r, int c) {
  v2i vis(121, vi(121, 0));
  int nr, nc, s;
  queue<tuple<int, int, int>> Q;
  Q.emplace(r, c, 0), vis[r][c] = 1;
  while (!Q.empty()) {
    tie(r, c, s) = Q.front(), Q.pop();
    if (r == 60 && c == 60) return s;
    for (int i = 0; i < 4; ++i) {
      if (!G[r][c][i]) continue;
      nr = r + DR[i], nc = c + DC[i];
      if (vis[nr][nc]) continue;
      vis[nr][nc] = 1, Q.emplace(nr, nc, s + 1);
    }
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    v3i G(121, v2i(121, vi(4, 0)));
    int r = 60, c = 60, k;
    char s;
    cin >> k;
    while (k--) {
      cin >> s;
      int _r = r, _c = c, d;
      switch (s) {
        case 'N': --r, d = 0; break;
        case 'E': ++c, d = 1; break;
        case 'S': ++r, d = 2; break;
        case 'W': --c, d = 3; break;
      }
      G[_r][_c][d] = 1;
      G[r][c][rev[d]] = 1;
    }
    printf("%d\n", bfs(G, r, c));
  }
  return 0;
}
