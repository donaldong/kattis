#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> v2i;

int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};
int R, C;
vs G;
v2i vis;

void dfs(int r, int c) {
  int r1, c1, add = 1;
  for (int i = 0; i < 4; ++i) {
    r1 = r + DR[i], c1 = c + DC[i];
    if (r1 < 0 || c1 < 0 || r1 >= R || c1 >= C) continue;
    if (G[r1][c1] == 'E') add = 0;
  }
  if (add) G[r][c] = 'E';
  for (int i = 0; i < 4; ++i) {
    r1 = r + DR[i], c1 = c + DC[i];
    if (r1 < 0 || c1 < 0 || r1 >= R || c1 >= C) continue;
    if (G[r1][c1] == '#' || vis[r1][c1]) continue;
    vis[r1][c1] = 1, dfs(r1, c1);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> R >> C;
  G.resize(R);
  for (auto &s : G) cin >> s;
  vis.assign(R, vi(C, 0));
  for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {
    if (G[i][j] != '#' && !vis[i][j]) vis[i][j] = 1, dfs(i, j);
  }
  for (auto &s : G) printf("%s\n", s.c_str());
  return 0;
}
