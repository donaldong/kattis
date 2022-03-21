#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int n) {
  ll res = 1;
  int k = 0;
  while (n % 2 == 0) n /= 2, ++k;
  if (k) res *= pow(k, 2);

  for (ll i = 3; i * i <= n; i += 2) {
    k = 0;
    while (n % i == 0) n /= i, ++k;
    if (k) res *= pow(k, i);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n) printf("%d %lld\n", n, solve(n));
  return 0;
}
