#include <bits/stdc++.h>
using namespace std;

using ti = tuple<int, int>;
using vti = vector<ti>;
using tmap = map<int, int>;

vti X, Y;

bool solve() {
  tmap lo, hi;
  int x, i, y1, y2, a, b;
  for (auto &t : X) {
    tie(x, i) = t;
    auto &y = Y[i > 0 ? i : -i];
    tie(y1, y2) = y;
    if (i < 0) lo.erase(y1), hi.erase(-y2);
    auto itr = lo.lower_bound(y1);
    if (itr != lo.end()) {
      a = itr->first;
#ifdef DEBUG
    printf("y in [%d %d]: found %d, below current upper bound %d ?\n", y1, y2, a, y2);
#endif
      if (a < y2) return true;
    }
    itr = hi.lower_bound(-y2);
    if (itr != hi.end()) {
      b = -itr->first;
#ifdef DEBUG
    printf("y in [%d %d]: found %d, above current lower bound %d ?\n", y1, y2, b, y1);
#endif
      if (b > y1) return true;
    }
    if (i > 0) lo[y1] = y2, hi[-y2] = y1;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  int n, a, b, c, d;
  scanf("%d", &n);

  X.reserve(2 * n); Y.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d %d", &a, &b, &c, &d);
    X.emplace_back(a, i), X.emplace_back(c, -i);
    Y[i] = make_tuple(b, d);
  }
  sort(X.begin(), X.end());
  printf("%d\n", solve());
  return 0;
}
