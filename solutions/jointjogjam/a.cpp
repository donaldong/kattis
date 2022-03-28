/**
 * @date        2022-03-27
 * @tags        math, geometry
 * @difficulty  1150
 */
#include <bits/stdc++.h>
using namespace std;
using Pair = pair<double, double>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  vector<Pair> P(4);
  for (auto& p : P) cin >> p.first >> p.second;
  double a = 0.0, b = 0.0, c = 0.0;
  double k = (P[2].first-P[0].first)-(P[3].first-P[1].first);
  double d = P[0].first-P[1].first;
  a += k*k, b += 2.0*d*k, c += d*d;

  k = (P[2].second-P[0].second)-(P[3].second-P[1].second);
  d = P[0].second-P[1].second;
  a += k*k, b += 2.0*d*k, c += d*d;

  cout << setprecision(12) << sqrt(max(c, a+b+c)) << endl;
  return 0;
}
