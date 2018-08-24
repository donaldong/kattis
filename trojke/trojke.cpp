#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using ti2 = tuple<int, int>;
using ld = long double;

int N;
vs G;

ti2 delta(ti2 &A, ti2 &B) {
  return make_tuple(
    get<0>(A) - get<0>(B),
    get<1>(A) - get<1>(B)
  );
}

ld arg(ti2 &p) {
  return atan2(get<1>(p), get<0>(p));
}

bool line(ti2 &A, ti2 &B, ti2 &C) {
  ti2 ab = delta(B, A);
  ti2 bc = delta(C, B);
  return abs(arg(ab) - arg(bc)) < 1e-9;
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
  int res = 0;
  for (size_t i = 0; i < P.size(); ++i) {
    for (size_t j = i + 1; j < P.size(); ++j) {
      for (size_t k = j + 1; k < P.size(); ++k) {
        if (line(P[i], P[j], P[k])) ++res;
      }
    }
  }
  cout << res << endl;
  return 0;
}
