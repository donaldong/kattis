#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using ti2 = tuple<int, int>;
using vi = vector<int>;
using v2i = vector<vi>;
using vti2 = vector<ti2>;
using ti3 = tuple<int, int, int>;

int INF = 1e9;

// U, R, D, L
int DR[] = {-1, 0, 1, 0};
int DC[] = {0, 1, 0, -1};

v2i bfs(vti2 V, int R, int C, vs &G, bool skip_d) {
  int r, c, step;
  v2i D(R, vi(C, INF));
  queue<ti2> Q;
  for (auto &t : V) {
    tie(r, c) = t;
    Q.push(t);
    D[r][c] = 0;
  }
  while (!Q.empty()) {
    tie(r, c) = Q.front(); Q.pop();
    for (int i = 0; i < 4; ++i) {
      int r2 = r + DR[i];
      int c2 = c + DC[i];
      if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C) {
        if (G[r2][c2] == 'X') continue;
        if (skip_d && G[r2][c2] == 'D') continue;
        if (D[r][c] + 1 < D[r2][c2]) {
          D[r2][c2] = D[r][c] + 1;
          Q.emplace(r2, c2);
        }
      }
    }
  }
  return D;
}

void debug(v2i &G) {
  cout << endl;
  for (auto &row : G) {
    for (auto &n : row) cout << n << " ";
    cout << endl;
  }
  cout << endl;
}

int solve(vs &G, v2i &DF, v2i &D, ti2 &src, int R, int C) {
  int r, c, step;
  queue<ti3> Q;
  v2i V(R, vi(C, 0));
  tie(r, c) = src;
  Q.emplace(0, r, c);
  while (!Q.empty()) {
    tie(step, r, c) = Q.front(); Q.pop();
    for (int i = 0; i < 4; ++i) {
      int r2 = r + DR[i];
      int c2 = c + DC[i];
      if (0 <= r2 && r2 < R && 0 <= c2 && c2 < C) {
        if (G[r2][c2] == 'D') return step + 1;
        if (G[r2][c2] == 'X' || V[r2][c2]) continue;
        V[r2][c2] = 1;
        if (D[r2][c2] < DF[r2][c2]) Q.emplace(step + 1, r2, c2);
      }
    }
  }
  return -1;
}

int main() {
  int r, c;
  cin >> r >> c;
  vs G(r);
  // List of cords for the flooded points 
  vti2 F;
  ti2 src;
  for (int i = 0; i < r; ++i) {
    cin >> G[i];
    for (int j = 0; j < c; ++j) {
      if (G[i][j] == '*') F.emplace_back(i, j);
      else if (G[i][j] == 'S') src = make_tuple(i, j);
    }
  }
  auto G1 = bfs(F, r, c, G, true);
  auto G2 = bfs({src}, r, c, G, false);
  int res = solve(G, G1, G2, src, r, c);
  if (res < 0) cout << "KAKTUS";
  else cout << res;
  cout << endl;
  return 0;
}

