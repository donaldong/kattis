#include <bits/stdc++.h>
using namespace std;

using hset = unordered_set<int>;
using vs = vector<string>;
using vb = vector<bool>;
using v2b = vector<vb>;

// Grid
vs G(9);

int index(int i, int j) {
  i /= 3;
  j /= 3;
  return 3 * i + j;
}

int build() {
  int res = 0;
  hset N;
  // rows, cols, boxes
  v2b R(9, vb(9, false)), C(9, vb(9, false)), B(9, vb(9, false));
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      int b = index(i, j);
      if (G[i][j] == '.') continue;
      int n = G[i][j] - '1';
      N.insert(n);
      if (R[i][n]) return -1;
      R[i][n] = true;
      if (C[j][n]) return -1;
      C[j][n] = true;
      if (B[b][n]) return -1;
      B[b][n] = true;
    }
  }
  vector<vector<int>> B2(9, vector<int>(9, 0));
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (G[i][j] != '.') continue;
      int b = index(i, j);
      bool f = true;
      for (int n = 0; n < 9; ++n) {
        if (R[i][n] || C[j][n] || B[b][n]) continue;
        ++B2[b][n];
        f = false;
      }
      if (f) return -1;
    }
  }
  for (int i = 0; i < 9; ++i) {
    for (int n : N) {
      if (!B[i][n] && !B2[i][n]) return -1;
    }
  }
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      if (G[i][j] != '.') continue;
      int b = index(i, j);
      for (int n = 0; n < 9; ++n) {
        if (R[i][n] || C[j][n] || B[b][n]) continue;
        if (B2[b][n] == 1) {
          G[i][j] = '1' + n;
          ++res;
        }
      }
    }
  }
  if (res) if (build() == -1) return -1;
  return 0;
}

int main() {
  for (int i = 0; i < 9; ++i) getline(cin, G[i]);
  if (build() == -1) cout << "ERROR" << endl;
  else for (auto &row : G) cout << row << endl;
  return 0;
}
