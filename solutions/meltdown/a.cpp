/**
 * @date        2022-12-25
 * @tags        geometry, binary search
 * @difficulty  1600
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n,x,y,v,c;
  while (cin >> n >> x >> y >> v >> c) {
    if (!n) break;
    vector<pair<int,int>> N(n);
    for (auto& p : N) cin >> p.first >> p.second;

    double res = 1e9;
    auto f = [&](int i, int j, double p) -> double {
      auto [x1,y1] = N[i];
      auto [x2,y2] = N[j];
      auto x0 = p*x1+(1.0-p)*x2;
      auto y0 = p*y1+(1.0-p)*y2;
      auto dx = x0-x;
      auto dy = y0-y;
      double t = sqrt(dx*dx+dy*dy)/c+y0/v;
      res = min(res, t);
      return t;
    };
    for (int i = 0; i < n; ++i) {
      int j = (i+1)%n;
      double lo = 0.0, hi = 1.0;
      for (int k = 0; k < 1000; ++k) {
        double m1 = (2*lo+hi)/3, m2 = (lo+2*hi)/3;
        if (f(i,j,m1)<f(i,j,m2)) hi = m2;
        else lo = m1;
      }
    }
    printf("%.4lf\n", res);
  }
  return 0;
}
