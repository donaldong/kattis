#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve(ll n) {
  return n * (n + 1) / 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  ll res = solve(n);

  int a = 0, b = 0;
  while (k--) {
    cin >> b;
    res -= solve(b - a - 1);
    a = b;
  }
  res -= solve(n - b);

  printf("%lld\n", res);
  return 0;
}
