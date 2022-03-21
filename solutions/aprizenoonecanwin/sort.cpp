#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x;
  cin >> n >> x;

  uint P[n];
  for (int i = 0; i < n; ++i) cin >> P[i];

  sort(P, P + n);
  int lo = 1, hi = n, mid;
  while (lo + 1 < hi) {
    mid = (lo + hi) >> 1;
    if (P[mid - 1] + P[mid] > x) hi = mid;
    else lo = mid;
  }
  if (n == 1 || P[lo - 1] + P[lo] > x) printf("1\n");
  else printf("%u\n", lo + 1);

  return 0;
}
