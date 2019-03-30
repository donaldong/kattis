#include <bits/stdc++.h>
using namespace std;

typedef vector<bool> vb;
typedef vector<vb> v2b;
typedef tuple<int, int> tup;
typedef vector<int> vi;
typedef vector<tup> vtup;
vector<string> G;
vtup X;
int R, C, aa = 0, ab = 0, ai= 0;
int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

#ifdef DEBUG
void print_grid() {
  cout << endl;
  for (auto &row : G) cout << row << endl;
  cout << endl;
}
#endif

bool intersection(int r, int c) {
  if (G[r][c] != 'X') return false;
  int r2, c2;
  for (int i = 0; i < 4; ++i) {
    r2 = r + DR[i], c2 = c + DC[i];
    if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) return false;
    if (G[r2][c2] != 'X') return false;
  }
  G[r][c] = 'I';
  return true;
}

void fill(const tup &t, char x) {
  int r, c, r2, c2;
  tie(r, c) = t;
  queue<tup> Q;
  Q.push(t), G[r][c] = x;
  while (!Q.empty()) {
    tie(r, c) = Q.front(), Q.pop();
    for (int i = 0; i < 4; ++i) {
      r2 = r + DR[i], c2 = c + DC[i];
      if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) continue;
      if (G[r2][c2] == 'I') r2 += DR[i], c2 += DC[i];
      if (G[r2][c2] == '.' || G[r2][c2] == x) continue;
      G[r2][c2] = x, Q.emplace(r2, c2);
    }
  }
}

bool in(int r, int c, char x) {
  int r2, c2;
  queue<tup> Q;
  v2b vis(R, vb(C, false));
  Q.emplace(r, c), vis[r][c] = true;
  while (!Q.empty()) {
    tie(r, c) = Q.front(), Q.pop();
    for (int i = 0; i < 4; ++i) {
      r2 = r + DR[i], c2 = c + DC[i];
      if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) return false;
      if (G[r2][c2] == x || G[r2][c2] == 'I' || vis[r2][c2]) continue;
      vis[r2][c2] = true, Q.emplace(r2, c2);
    }
  }
  return true;
}

int bfs(int r, int c) {
  if (G[r][c] != '.') return 0;
  int r2, c2, res = 1;
  queue<tup> Q;
  Q.emplace(r, c), G[r][c] = 'X';
  while (!Q.empty()) {
    tie(r, c) = Q.front(), Q.pop();
    for (int i = 0; i < 4; ++i) {
      r2 = r + DR[i], c2 = c + DC[i];
      if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) return false;
      if (G[r2][c2] != '.') continue;
      ++res, G[r2][c2] = 'X', Q.emplace(r2, c2);
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int r, c, nr, nc;
  bool in_a, in_b;
  cin >> R >> C;
  G.resize(R);
  tup A, B;
  for (size_t i = 0; i < R; ++i) cin >> G[i];
  for (r = 0; r < R; ++r) for (c = 0; c < C; ++c) {
    if (intersection(r, c)) X.emplace_back(r, c);
    else if (G[r][c] == 'A') A = {r, c};
    else if (G[r][c] == 'B') B = {r, c};
  }
  fill(A, 'A'), fill(B, 'B');
#ifdef DEBUG
  print_grid();
#endif
  vi DX = {-1, 1};
  for (auto &x : X) {
    tie(r, c) = x;
    for (int dr : DX) for (int dc : DX) {
      nr = r + dr, nc = c + dc;
      in_a = in(nr, nc, 'A'), in_b = in(nr, nc, 'B');
      if (in_a && in_b) ai += bfs(nr, nc);
      else if (in_a) aa += bfs(nr, nc);
      else if (in_b) ab += bfs(nr, nc);
    }
  }
  printf("%d %d %d\n", aa, ab, ai);
  return 0;
}
