#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int MOD;

ll power(int a, int b) {
  if (b == 0) return 1;
  ll res = a;
  res *= a;
  if (b & 1) return (power(res % MOD, b / 2) * a) % MOD;
  return power(res % MOD, b / 2) % MOD;
}

bool is_prime(int n) {
  if (n % 2 == 0) return false;
  for (ll i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

bool valid(int p, int a) {
  if (is_prime(p)) return false;
  MOD = p;
  return power(a, p) == a;
}

int main() {
  int p, a;
  while (cin >> p >> a) {
    if (!p && !a) break;
    cout << (valid(p, a) ? "yes" : "no") << endl;
  }
  return 0;
}
