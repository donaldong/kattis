#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll q, m, s, l;
  cin >> q >> m >> s >> l;

  ll t = l / m;
  ll mod = l % m;
  if (mod) ++t;
  t *= q;
  ll r = mod ? (m - mod) * q : 0;
#ifdef DEBUG
  printf("used: %lld, remain: %lld, todo: %lld\n", t, r, s);
#endif
  if (r < s) {
    t += (s - r) / m;
    if ((s - r) % m) ++t;
  }
  printf("%lld\n", t);
  return 0;
}
