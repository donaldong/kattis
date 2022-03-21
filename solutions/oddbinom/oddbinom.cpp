#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll power(ll n) {
  if (!n) return 1;
  ll res = power(n / 2);
  if (n & 1) return res * res * 3;
  return res * res;
}

ll solve(ll n) {
  if (!n) return 0;
  if (n == 1) return 1;
  ll k = 1;
  int l = 0;
  while ((k << 1) <= n) k <<= 1, ++l;
  return solve(n - k) * 2 + power(l);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n;
  cin >> n;
  printf("%lld\n", solve(n));
  return 0;
}
