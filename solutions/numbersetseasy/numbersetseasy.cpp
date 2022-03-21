#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

ll A, B, P;

vll prime_factors(ll n) {
  vll res;
  if (!(n & 1) && 2 >= P) {
    res.push_back(2);
  }
  while (!(n & 1)) n /= 2;
  for (ll i = 3; i * i <= n; i += 2) {
    if (n % i == 0 && i >= P) res.push_back(i);
    while (n % i == 0) n /= i;
  }
  if (n > 1 && n >= P) res.push_back(n);
  return res;
}

size_t find(vll &N, ll n) {
  if (N[n] != n) {
    N[n] = find(N, N[n]);
  }
  return N[n];
}

void join(vll &N, size_t a, size_t b) {
  if (N[a] == N[b]) return;
  N[b] = a;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cout << "Case #" << t + 1 << ": ";
    cin >> A >> B >> P;
    ll size = B - A + 1;
    vll N(size);
    for (ll i = 0; i < size; ++i) N[i] = i;
    for (ll i = A; i <= B; ++i) {
      ll j = i - A;
      vll factors = prime_factors(i);
      for (auto f : factors) {
        for (ll cur = i + f; cur <= B; cur += f) {
          auto ra = find(N, j);
          auto rb = find(N, cur - A);
          if (ra != rb) join(N, ra, rb);
        }
      }
    }
    int res = 0;
    for (ll i = 0; i < size; ++i) {
      if (N[i] == i) ++res;
    }
    cout << res << endl;
  }
  return 0;
}
