#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;
using v2i = vector<vi>;
using ti2 = tuple<int, int>;

int N;
vs G;

int solve(ti2 &a, ti2 &b) {
  int dr = get<0>(b) - get<0>(a);
  int dc = get<1>(b) - get<1>(a);
  int res = 2;
  int r, c;
  tie(r, c) = a;
  r -= dr;
  c -= dc;
  // avoid multiple counting
  if (0 <= r && r < N && 0 <= c && c < N && G[r][c] != '.') return 0;
  tie(r, c) = b;
  r += dr;
  c += dc;
  while (0 <= r && r < N && 0 <= c && c < N) {
    if (G[r][c] != '.') ++res;
    r += dr;
    c += dc;
  }
  return res;
}

int C(int n) {
  return n * (n - 1) * (n - 2) / 6;
}

int main() {
  cin >> N;
  G = vs(N);
  vector<ti2> P;
  for (auto &row : G) cin >> row;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      char c = G[i][j];
      if (c == '.') continue;
      P.emplace_back(i, j);
    }
  }
  long long res = 0;
  for (size_t i = 0; i < P.size(); ++i) {
    for (size_t j = i + 1; j < P.size(); ++j) {
      int n = solve(P[i], P[j]);
      if (n >= 3) res += C(n);
    }
  }
  cout << res << endl;
  return 0;
}
