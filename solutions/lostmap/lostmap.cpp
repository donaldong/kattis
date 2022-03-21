#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;

void debug(v2i &G) {
  for (auto &row : G) {
    for (auto &cell : row) cout << cell << " ";
    cout << endl;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  v2i G(n, vi(n));
  for (auto &row : G) for (auto &cell : row) cin >> cell;
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      if (!G[i][k]) continue;
      for (int j = i + 1; j < n; ++j) {
        if (!G[k][j]) continue;
        if (G[i][k] + G[k][j] == G[i][j]) G[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (G[i][j]) cout << i + 1 << " " << j + 1 << endl;
    }
  }
  return 0;
}
