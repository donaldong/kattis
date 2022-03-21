#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using hmap = map<ll, int>;

hmap prime_factors(ll n) {
  hmap F;
  while (n % 2 == 0) ++F[2], n /= 2;
  for (ll i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      ++F[i];
      n /= i;
    }
  }
  if (n > 1) ++F[n];
  return F;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  while (cin >> n) {
    if (n < 0) {
      cout << "-1 ";
      n *= -1;
    }
    auto F = prime_factors(n);
    bool f = true;
    for (auto &entry : F) {
      if (!f) cout << ' ';
      f = false;
      if (entry.second == 1) cout << entry.first;
      else cout << entry.first << '^' << entry.second;
    }
    cout << '\n';
  }
  cout << flush;
  return 0;
}
