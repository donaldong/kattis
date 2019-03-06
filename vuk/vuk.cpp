#include <bits/stdc++.h>
using namespace std;

using ti = tuple<int, int>;
using vti = vector<ti>;
using v2ti = vector<vti>;
using vs = vector<string>;
using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;
using v2b = vector<vb>;
using v3b = vector<v2b>;
int DR[] = {-1, 0, 1, 0};
int DC[] = {0, 1, 0, -1};
v3b T;
v2b vis;
v2i D;
v2ti P;
vs G;
int src_r, src_c, dst_r, dst_c, n, m;

void mst() {
  int d, i, j, k, r, c, dir;
  multiset<tuple<int, int, int, int>> Q;
  i = src_r, j = src_c;
  for (k = 0; k < 4; ++k) {
    r = i + DR[k], c = j + DC[k];
    if (r < 0 || r >= n || c < 0 || c >= m) continue;
    Q.insert({D[r][c], i, j, k});
  }
  vis[i][j] = true;
  while (!Q.empty()) {
    auto itr = --Q.end();
    tie(d, i, j, dir) = *itr;
    r = i + DR[dir], c = j + DC[dir];
    if (vis[r][c]) {
      Q.erase(itr);
      continue;
    }
    T[i][j][dir] = true;
    vis[r][c] = true;
    Q.erase(itr);
#ifdef DEBUG
    printf("%d %d %d\n", i, j, dir);
#endif
    i = r, j = c;
    for (k = 0; k < 4; ++k) {
      r = i + DR[k], c = j + DC[k];
      if (r < 0 || r >= n || c < 0 || c >= m) continue;
      if (vis[r][c]) continue;
      Q.insert({D[r][c], i, j, k});
    }
  }
#ifdef DEBUG
  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      printf("[");
      for (k = 0; k < 4; ++k) {
        printf("%d ", T[i][j][k] ? 1 : 0);
      }
      printf("] ");
    }
    printf("\n");
  }
#endif
}

void dfs(int i, int j) {
#ifdef DEBUG
    int a, b;
    tie(a, b) = P[i][j];
    printf("dfs: %d %d => %d %d\n", a, b, i, j);
#endif
  int k = 0, r, c;
  for (k = 0; k < 4; ++k) {
    if (!T[i][j][k]) continue;
    int r = i + DR[k], c = j + DC[k];
    P[r][c] = {i, j};
    if (r == dst_r && c == dst_c) return;
    dfs(r, c);
  }
}

int solve() {
  int i = dst_r, j = dst_c, r, c;
  int res = D[i][j];
  while (true) {
    tie(r, c) = P[i][j];
#ifdef DEBUG
    printf("%d %d => %d %d\n", r, c, i, j);
#endif
    if (r < 0 || c < 0) return res;
    res = min(res, D[r][c]);
    i = r, j = c;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j, k, r, c;
  cin >> n >> m;

  G.resize(n);
  D.assign(n, vi(m, 1e9)), P.assign(n, vti(m, {-1, -1}));
  vis.assign(n, vb(m, false));
  T.assign(n, v2b(m, vb(4, false)));
  queue<ti> Q;
  for (i = 0; i < n; ++i) {
    cin >> G[i];
    for (j = 0; j < m; ++j) {
      if (G[i][j] == '+') D[i][j] = 0, Q.emplace(i, j);
      else if (G[i][j] == 'V') src_r = i, src_c = j;
      else if (G[i][j] == 'J') dst_r = i, dst_c = j;
    }
  }
  // Fill D (dist)
  while (!Q.empty()) {
    tie(i, j) = Q.front(), Q.pop();
    for (k = 0; k < 4; ++k) {
      r = i + DR[k], c = j + DC[k];
      if (r < 0 || r >= n || c < 0 || c >= m) continue;
      if (D[i][j] + 1 < D[r][c] && G[r][c] != '+') {
        D[r][c] = D[i][j] + 1;
        Q.emplace(r, c);
      }
    }
  }
#ifdef DEBUG
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      printf("%d ", D[i][j]);
    }
    printf(" ### D\n");
  }
#endif
  mst();
  dfs(src_r, src_c);
  printf("%d\n", solve());
  return 0;
}
