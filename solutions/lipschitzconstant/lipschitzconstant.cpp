#include <bits/stdc++.h>
using namespace std;

typedef tuple<double, double> tup;
typedef vector<int> vi;
typedef vector<tup> vtup;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  double a, b, res = DBL_MIN;
  cin >> n;
  vtup N;
  N.reserve(n);
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    N.emplace_back(a, b);
  }
  sort(N.begin(), N.end());
  for (int i = 1; i < n; ++i) {
    double dy = get<1>(N[i]) - get<1>(N[i - 1]);
    double dx = get<0>(N[i]) - get<0>(N[i - 1]);
    res = max(res, abs(dy / dx));
  }
  printf("%.5lf\n", res);
  return 0;
}
