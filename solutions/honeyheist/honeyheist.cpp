#include <bits/stdc++.h>
using namespace std;

#define hset unordered_set

struct node {
  bool wall, visited = false;
  int i, step = 0;
  node() {}
};

int R, N, A, B, X;
// Grid
vector<vector<node>> G;
tuple<int, int> SRC;

void build(hset<int> &W) {
  int l = 2 * R - 1;
  G = vector<vector<node>>(l);
  int r = R;
  int count = 1;
  for (int i = 0; i < R; ++i) {
    G[i] = vector<node>(r);
    for (int j = 0; j < r; ++j) {
      if (count == A) SRC = make_tuple(i, j);
      G[i][j].i = count;
      G[i][j].wall = W.find(count) != W.end();
      ++count;
    }
    ++r;
  }
  r = 1;
  for (int k = 0; k < R - 1; ++k) {
    int i = k + R;
    G[i] = vector<node>(l);
    for (int j = 0; j < r; ++j) {
      G[i][j].wall = true;
    }
    for (int j = r; j < l; ++j) {
      if (count == A) SRC = make_tuple(i, j);
      G[i][j].i = count;
      G[i][j].wall = W.find(count) != W.end();
      ++count;
    }
    ++r;
  }
}

int DR[] = {-1, 0, 1, 1, 0, -1};
int DC[] = {0, 1, 1, 0, -1, -1};

int bfs() {
  queue<tuple<int, int>> Q;
  int r, c;
  tie(r, c) = SRC;
  Q.push(SRC);
  G[r][c].visited = true;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int i = 0; i < 6; ++i) {
      tie(r, c) = cur;
      int step = G[r][c].step;
      if (step == N) break;
      r += DR[i];
      c += DC[i];
      if (r < 0 || r >= G.size()) continue;
      if (c < 0 || c >= G[r].size()) continue;
      if (G[r][c].wall || G[r][c].visited) continue;
      G[r][c].visited = true;
      G[r][c].step = step + 1;
      if (G[r][c].i == B) return G[r][c].step;
      Q.push(make_tuple(r, c));
    }
  }
  return -1;
}

int main() {
  cin >> R >> N >> A >> B >> X;
  // Wall
  hset<int> W;
  while (X--) {
    int w;
    cin >> w;
    W.insert(w);
  }
  build(W);
  int res = bfs();
  if (res < 0) cout << "No" << endl;
  else cout << res << endl;
  return 0;
}
