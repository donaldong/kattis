#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int MOD = 1e4;

ll solve(ll a, ll b) {
  if (!b) return 1;
  ll res = solve(a, b / 2);
  if (b & 1) return (a * res * res) % MOD;
  return (res * res) % MOD;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ll a, b;
  char s;
  while (cin >> a >> s >> b) {
    a %= MOD;
    if (s == '+') printf("%lld\n", (a + b) % MOD);
    else if (s == '*') printf("%lld\n", (a * b) % MOD);
    else printf("%lld\n", solve(a, b));
  }
  return 0;
}
