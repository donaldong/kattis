#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef vector<int> vi;

ld delta(int a, int b, int k) {
#ifdef DEBUG
  printf("%d => %d + %d\n", a, b, k);
#endif
  ld d = b - a;
  ld p = k;
  p = 1.0 + p / 100.0;
  return d * p;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, p, k;
  ld res = 0.0;
  cin >> n >> p >> k;
  vi N(n);
  for (int i = 0; i < n; ++i) cin >> N[i];
  res += delta(N[n - 1], k, n * p);
  for (int i = n - 2; i >= 0; --i) {
    res += delta(N[i], N[i + 1], (i + 1) * p);
  }
  res += delta(0, N[0], 0);
  printf("%.7Lf\n", res);
  return 0;
}
