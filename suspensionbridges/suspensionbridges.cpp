#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  double d, s, lo = 0, hi = 1e9, a, v;
  cin >> d >> s;
  for (int i = 0; i < 100; ++i) {
    a = (lo + hi) / 2;
    v = a + s - a * cosh(d / 2.0 / a);
    if (v > 0) hi = a;
    else lo = a;
  }
  printf("%.5lf\n", 2.0 * a* sinh(d / 2.0 / a));
  return 0;
}
