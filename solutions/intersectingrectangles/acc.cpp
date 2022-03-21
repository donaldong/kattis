#include <bits/stdc++.h>
using namespace std;

using ti = tuple<int, int>;
using vti = vector<ti>;
using tmap = map<int, int>;
using pp = const pair<const int, int>*;

vti X, Y;

bool solve() {
  tmap lo;
  int x, i, y1, y2, yi, yj;
  for (auto &t : X) {
    tie(x, i) = t;
    auto &y = Y[i > 0 ? i : -i];
    tie(y1, y2) = y;
    if (i < 0) lo.erase(y1);
    auto itr = lo.lower_bound(y1);
    if (itr != lo.end()) {
      yi = itr->first, yj = itr->second;
      if (i > 0) {
        // Enter
        // r.y1 < yi && yj < r.y2 || r.y1 < yi && yi < r.y2
        if ((y1 < yi && yj < y2) || (y1 < yi && yi < y2)) return true;
      } else {
        // Leave
        // r.y1 < yi && yj < r.y2 || yi < r.y2 && r.y2 < yj
        if ((y1 < yi && yj < y2) || (yi < y2 && y2 < yj)) return true;
      }
    }
    if (i > 0) lo[y1] = y2;
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
