#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tup;
typedef vector<int> vi;
typedef long long ll;
int MOD = 1e9 + 7;
int MAX_N = 2e5 + 1;
vi F(MAX_N);

tup egcd(int a, int b) {
  if (!a) return {b, 0, 1};
  int g, y, x;
  tie(g, y, x) = egcd(b % a, a);
  return {g, x - b / a * y, y};
}

int modinv(int a) {
  int g, x, y;
  tie(g, x, y) = egcd(a, MOD);
  return (x % MOD + MOD) % MOD;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  F[0] = F[1] = 1;
  for (ll i = 2; i < MAX_N; ++i) F[i] = (F[i - 1] * i) % MOD;
  int n;
  cin >> n;
  ll k = F[n];
  k *= F[n + 1];
  k = modinv(k % MOD);
  printf("%lld\n", (k * F[2 * n]) % MOD);
  return 0;
}
