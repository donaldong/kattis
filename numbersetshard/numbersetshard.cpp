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

ll find(vll &N, ll n) {
  if (N[n] == -1) {
    return n;
  }
  return N[n] = find(N, N[n]);
}

void join(vll &N, ll a, ll b) {
  N[b] = a;
}

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cout << "Case #" << t + 1 << ": ";
    cin >> A >> B >> P;
    ll size = B - A + 1;
    vll N(size, -1);
    vector<bool> V(size, false);
    for (ll i = A; i <= B; ++i) {
      ll j = i - A;
      if (V[j]) continue;
      V[j] = true;
      vll factors = prime_factors(i);
      for (auto f : factors) {
        for (ll cur = i + f; cur <= B; cur += f) {
          ll k = cur - A;
          auto ra = find(N, j);
          auto rb = find(N, k);
          if (ra != rb) join(N, ra, rb);
          V[k] = true;
        }
      }
    }
    int res = 0;
    for (ll i = 0; i < size; ++i) {
      if (N[i] == -1) ++res;
    }
    cout << res << endl;
  }
  return 0;
}
