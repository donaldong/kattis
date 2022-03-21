#include <bits/stdc++.h>
using namespace std;
int R, C;
vector<string> G;

void dfs(int r, int c) {
  if (r+1>=R) return;
  if (G[r+1][c] == 'V') return;

  if (G[r+1][c] == '.') {
    G[r+1][c] = 'V';
    dfs(r+1, c);
    return;
  }

  int c2 = c-1;
  if (c2 >= 0 && c2 < C && G[r][c2] == '.') {
    G[r][c2] = 'V';
    dfs(r, c2);
  }

  c2 = c+1;
  if (c2 >= 0 && c2 < C && G[r][c2] == '.') {
    G[r][c2] = 'V';
    dfs(r, c2);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C;
  G.resize(R);
  for (auto& row : G) cin >> row;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (G[i][j] == 'V') dfs(i, j);
    }
  }
  for (auto& row : G) cout << row << endl;
  return 0;
}
