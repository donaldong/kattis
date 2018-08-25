#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;

int R, C;
vs G;

void solve() {
  // row count, column count
  int total = 0;
  vi RC(C, 0), CC(R, 0);
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (G[i][j] == '1') ++RC[j], ++CC[i], ++total;
    }
  }
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (G[i][j] == '0') G[i][j] = 'N';
      else if (RC[j] == 1 && CC[i] == 1 && total > 1) {
        cout << "impossible" << endl;
        return;
      } else if (RC[j] > 1 && CC[i] > 1) G[i][j] = 'I';
      else G[i][j] = 'P';
    }
  }
  for (auto &row : G) cout << row << endl;
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
