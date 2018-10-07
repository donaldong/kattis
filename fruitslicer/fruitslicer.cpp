#include <bits/stdc++.h>
using namespace std;

using ld = long double;

struct pt {
  int x, y;
  pt() {}
  pt(int x, int y) : x(x), y(y) {}
};

using vpt = vector<pt>;
using ti3 = tuple<ld, ld, ld>;
using ll = long long;

ti3 tangent(pt &A, pt &B) {
  ld a, b, c, dy = B.y - A.y, dx = B.x - A.x;
  if (dx < 1e-8) a = 1, b = 0, c = -A.x;
  else {
    a = - dy / dx;
    b = 1;
    c = - (a * A.x) - A.y;
  }
  ld theta = atan2(b, a) + M_PI_2;
  dy = sin(theta);
  return {
    {a, b, c + dy},
    {a, b, c - dy}
  };
}

bool in_range(pt &p, ti3 &line) {
  ld a, b, c;
  tie(a, b, c) = line;
  ld l = a * p.x + b * p.y + c;
  return l * l <= (a * a + b * b) * 4.0;
}

int main() {
  int n;
  float x, y;
  cin >> n;
  vpt points(n);
  for (auto &p : points) {
    cin >> x >> y;
    p.x = x * 100;
    p.y = y * 100;
  }
  int res = 0;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      auto lines = tangent(points[i], points[j]);
      for (auto &line : lines) {
        int r = 0;
        for (auto &p : points) if (in_range(p, line)) ++r;
        res = max(res, r);
      }
    }
  }
  cout << res << endl;
  return 0;
}
