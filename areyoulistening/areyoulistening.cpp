#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int x0, y0, n, x, y, r;
  cin >> x0 >> y0 >> n;

  double D[n];
  for (int i = 0; i < n; ++i) {
    cin >> x >> y >> r;
    int dx = x0 - x, dy = y0 - y;
    D[i] = sqrt(dx * dx + dy * dy) - r;
  }

  sort(D, D + n);
  printf("%d\n", max((int)floor(D[2]), 0));

  return 0;
}
