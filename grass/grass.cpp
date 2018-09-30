#include <bits/stdc++.h>
using namespace std;

using ld = long double;
ld EPS = 1e-8;

struct interval {
  ld l, r;
  interval() {}
  interval(ld l, ld r) : l(l), r(r) {}
};

using intervals = vector<interval>;

ld calc(ld w, ld r) {
  return sqrt(r * r - w * w);
}

int solve(intervals &I, int l) {
  if (I[0].l > EPS) return -1;
  int res = 1;
  ld r = 0;
  for (size_t i = 0; i < I.size();) {
    ld nr = r;
    size_t j = i;
    while (j < I.size() && I[j].l < r + EPS) {
      if (I[j].r > nr) nr = I[j].r;
      ++j;
    }
    if (i == j) break;
    r = nr;
    if (r > l) return res;
    i = j;
    ++res;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l, x, r;
  ld w, a, b;
  while (cin >> n >> l >> w) {
    w /= 2;
    intervals I;
    I.reserve(n);
    for (int i = 0; i < n; ++i) {
      cin >> x >> r;
      if (r <= w) continue;
      ld dl = calc(w, r);
      a = x - dl, b = x + dl;
      I.emplace_back(a, b);
    }
    sort(I.begin(), I.end(), [](interval &a, interval &b) {
      return a.l < b.l;
    });
    cout << solve(I, l) << endl;
  }
  return 0;
}
