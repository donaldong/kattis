#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using v2b = vector<vb>;

int count(string &s, int odd, vb &M) {
  char t = '0' + odd;
  int res = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    if (s[i] == t) continue;
    ++res;
    M[i] = true;
  }
  return res;
}

int main() {
  string row, col;
  cin >> row >> col;
  int R = row.size(), C = col.size();
  vb row_mark(R, false), col_mark(C, false);
  int dr = count(row, C & 1, row_mark), dc = count(col, R & 1, col_mark);
  if ((dr & 1) != (dc & 1)) cout << "-1" << endl;
  else {
    v2b G(R, vb(C, true));
    if (dr > dc) for (int i = 0, c = dr - dc; i < R && c > 0; ++i) {
      if (row_mark[i]) row_mark[i] = G[i][0] = 0, --c;
    }
    else if (dr < dc) for (int i = 0, r = dc - dr; i < C && r > 0; ++i) {
      if (col_mark[i]) col_mark[i] = G[0][i] = 0, --r;
    }
    for (int r = 0; r < R; ++r) for (int c = 0; c < C; ++c) {
      if (row_mark[r] && col_mark[c]) {
        G[r][c] = 0;
        row_mark[r] = col_mark[c] = false;
      }
    }
    for (auto &row : G) {
      for (auto cell : row) cout << cell;
      cout << endl;
    }
  }
  return 0;
}
