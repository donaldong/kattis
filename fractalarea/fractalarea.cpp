#include <bits/stdc++.h>
using namespace std;

int N;

double solve(double r, int n) {
  if (!n) return 0.0;
  double A = M_PI * r * r;
  double res = solve(r / 2, n - 1);
  if (n == N) res *= 4;
  else res *= 3;
  return res + A;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t, r, n;
  cin >> t;
  while (t--) {
    cin >> r >> N;
    printf("%.7lf\n", solve(r, N));
  }
  return 0;
}
