#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
ll MOD = 1e9 + 7;

void debug(vll &X) {
  cout << endl;
  for (auto x : X) cout << x << " ";
  cout << endl;
}

ll mod_power(ll a, ll n) {
  if (n == 0) return 1;
  ll res = mod_power(a, n / 2); 
  res = (res * res) % MOD;
  if (n & 1) return (res * a) % MOD;
  return res;
}

// Ref
//  https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
ll mod_inv(ll n) {
  return mod_power(n, MOD - 2);
}

ll C(vll &P, int n, int r) {
  return (P[n] * mod_inv((P[r] * P[n - r]) % MOD)) % MOD;
}

vll solve(vll &P, int n, int m, int k) {
  vll R(k + 1);
  R[1] = 1;
  for (size_t i = 2; i <= k; ++i) {
    R[i] = C(P, n - (m - 1) * i - 1, i - 1);
  }
  return R;
}

int main() {
  int n, x, y, k;
  cin >> n >> x >> y;
  k = n / max(x, y);
  vll P(n + 1);
  P[0] = P[1] = 1;
  for (size_t i = 2; i < P.size(); ++i) P[i] = (P[i - 1] * i) % MOD;
  auto X = solve(P, n, x, k);
  auto Y = solve(P, n, y, k);
  ll res = 1;
  for (int i = 2; i <= k; ++i) res += (X[i] * Y[i]) % MOD, res %= MOD;
  cout << res << endl;
  return 0;
}
