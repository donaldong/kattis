#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  ll t, pt;
  double v, pv;
  cin >> n;
  cin >> pt >> pv;
  --n;
  double res = 0;
  while (n--) {
    cin >> t >> v;
    res += (v + pv) / 2.0 * (t - pt);
    pt = t, pv = v;
  }
  printf("%.7lf\n", res / 1000.0);
  return 0;
}
