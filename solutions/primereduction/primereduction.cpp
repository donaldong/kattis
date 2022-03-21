#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

vll prime_factors(ll n) {
  vll R;
  while (n % 2 == 0) {
    n /= 2;
    R.push_back(2);
  }
  for (ll i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      n /= i;
      R.push_back(i);
    }
  }
  if (n > 1) R.push_back(n);
  return R;
}


void solve(ll &n, ll &count) {
  count = 0;
  while (true) {
    auto F = prime_factors(n);
    ++count;
    n = 0;
    for (auto f : F) n += f;
    if (F.size() == 1) return;
  }
}

int main() {
  ll n;
  while (cin >> n) {
    if (n == 4) break;
    ll c;
    solve(n, c);
    cout << n << " " << c << endl;
  }
  return 0;
}
