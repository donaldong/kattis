#include <bits/stdc++.h>
using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> v2i;
int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};
vs G;

int solve() {
  int res = 0, d, nd, r, c, n = G.size(), r1, c1;
  v2i D(n, vi(n, 1e9));
  priority_queue<tuple<int, int, int>> Q;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (G[i][j] == 'H') Q.emplace(0, i, j), D[i][j] = 0;
  }
  while (!Q.empty()) {
    tie(d, r, c) = Q.top(), Q.pop();
    d *= -1;
    for (int i = 0; i < 4; ++i) {
      nd = d + 1, r1 = r + DR[i], c1 = c + DC[i];
      if (r1 < 0 || r1 >= n || c1 < 0 || c1 >= n) continue;
      if (nd < D[r1][c1]) {
        D[r1][c1] = nd;
        Q.emplace(-nd, r1, c1);
      }
    }
  }
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    if (G[i][j] == 'S') res = max(res, D[i][j]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  G.resize(n);
  for (auto &row : G) cin >> row;
  printf("%d\n", solve());
  return 0;
}
