/**
 * @date        2022-03-26
 * @tags        brute force, implementation, math
 * @difficulty  1300
 */
#include <bits/stdc++.h>
using namespace std;
bool possible(double C, double X, double M, int s, double f) {
  double costPerHour = X+s/f;
  double hours = M/s;
  return hours*costPerHour <= C/2.0;
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  double C,X,M,f;
  int res = -1, s;
  cin >> C >> X >> M;
  for (int i = 0; i < 6; ++i) {
    cin >> s >> f;
    if (possible(C,X,M,s,f)) res = max(res, s);
  }
  if (res < 0) cout << "NO" << endl;
  else cout << "YES " << res << endl;
  return 0;
}
