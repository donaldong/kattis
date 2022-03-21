#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int N;
int DR[] = {2, 2, -2, -2, 1, 1, -1, -1};
int DC[] = {1, -1, 1, -1, 2, -2, 2, -2};
vector<string> G;

int bfs(int r, int c) {
  if (G[r][c] == 'K') return 0;
  int r1, c1;
  v2i D(N, vi(N, -1));
  queue<tuple<int, int>> Q;
  D[r][c] = 0, Q.emplace(r, c);
  while (!Q.empty()) {
    tie(r, c) = Q.front(), Q.pop();
    for (int i = 0; i < 8; ++i) {
      r1 = r + DR[i], c1 = c + DC[i];
      if (r1 < 0 || c1 < 0 || c1 >= N || r1 >= N) continue;
      if (D[r1][c1] != -1 || G[r1][c1] == '#') continue;
      D[r1][c1] = D[r][c] + 1;
      if (G[r1][c1] == 'K') return D[r1][c1];
      Q.emplace(r1, c1);
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> N;
  G.resize(N);
  for (auto &row : G) cin >> row;
  printf("%d\n", bfs(0, 0));
  return 0;
}
