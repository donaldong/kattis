#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
vi V, W;
v2i M;

void debug() {
  cout << endl;
  for (auto &row : M) {
    for (auto &cell : row) cout << cell << " ";
    cout << endl;
  }
  cout << endl;
}

void display() {
  vi R;
  int r = M.size() - 1, c = M.back().size() - 1;
  while (r >= 1) {
    if (!M[r][c]) break;
    if (M[r][c] > M[r - 1][c]) {
      R.push_back(r);
      c -= W[r];
    }
    --r;
  }
  if (M[0][c] == V[0]) R.push_back(0);
  cout << R.size() << endl;
  for (auto itr = R.rbegin(); itr != R.rend(); ++itr) {
    cout << *itr << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double c;
  int n;
  while (cin >> c >> n) {
    W = vi(n), V = vi(n);
    M = v2i(n, vi(c + 1, 0));
    for (int i = 0; i < n; ++i) {
      cin >> V[i] >> W[i];
    }
    for (size_t i = W[0]; i < M.back().size(); ++i) {
      M[0][i] = V[0];
    }
    for (int i = 1; i < n; ++i) {
      for (int w = 1; w < c; ++w) {
        int res = M[i - 1][w];
        if (w >= W[i]) res = max(
          res, M[i - 1][w - W[i]] + V[i]
        );
        M[i][w] = res;
      }
    }
    display();
  }
  return 0;
}
