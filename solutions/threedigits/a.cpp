/**
 * @date        2022-03-26
 * @tags        dp
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  long long twos = 0, res = 1, n, mod=1000;
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    int j = i;
    while (j%2 == 0) ++twos, j >>= 1;
    while (j%5 == 0) --twos, j /= 5;
    res = (res*j)%mod;
  }
  while (twos--) res = (res*2)%mod;
  if (n<=6) printf("%lld\n", res);
  else printf("%03lld\n", res);
  return 0;
}
