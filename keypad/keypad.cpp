#include <bits/stdc++.h>
using namespace std;

using ti2 = tuple<int, int>;
using vs = vector<string>;
using vti2 = vector<ti2>;

int R, C;
vs G;

void solve() {
  vti2 P;
  vs res(R, string(C, 'N'));
  for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {
    if (G[i][j] == '1') P.emplace_back(i, j), res[i][j] = 'P';
  }
  int r0, c0, r1, c1; 
  for (size_t i = 0; i < P.size(); ++i) {
    tie(r0, c0) = P[i];
    for (size_t j = i + 1; j < P.size(); ++j) {
      tie(r1, c1) = P[j];
      if (r0 == r1 || c0 == c1) continue;
      if (G[r0][c1] == '0' || G[r1][c0] == '0') {
        cout << "impossible" << endl;
        return;
      }
      res[r0][c0] = 'I';
      res[r0][c1] = 'I';
      res[r1][c0] = 'I';
      res[r1][c1] = 'I';
    }
  }
  for (auto &row : res) cout << row << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> R >> C;
    G = vs(R);
    for (auto &row : G) cin >> row;
    solve();
    cout << "----------" << endl;
  }
  return 0;
}
