#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll power(int a, int k, int f) {
  if (!k) return 1;
  ll res = power(a, k / 2, f);
  if (res < 0 || res > f) return -1;
  if (k & 1) return res * res * a;
  return res * res;
}

int main() {
  ios::sync_with_stdio(0);

  int t, p, r, f;
  scanf("%d", &t);

  while (t--) {
    scanf("%d %d %d", &p, &r, &f);
    int res;
    for (res = 0; res <= 30; ++res) {
      ll k = power(r, res, f);
      if (k < 0 || k * p > f) break;
    }
    printf("%d\n", res);
  }
  return 0;
}
