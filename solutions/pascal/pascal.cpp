#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll least_prime_factor(ll n) {
  if (n % 2 == 0) return 2;
  for (ll i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return i;
  }
  return 1;
}

int solve(ll n) {
  if (n <= 1) return 0;
  ll r = least_prime_factor(n);
  if (r == n || r == 1) return n - 1;
  return n - n / r;
}

int main () {
  int n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
