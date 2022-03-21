#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;

ll A, B, P;

vll seive(ll n) {
  vll res;
  ll size = 1e6;
  vector<bool> p(size, true);
  for (ll i = 2; i < size; ++i) {
    if (!p[i]) continue;
    for (ll j = i * i; j < size; j += i) {
      p[j] = false;
    }
  }
  for (ll i = P; i < size; ++i) if (p[i]) res.push_back(i);
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
    vll primes = seive(B);
    for (auto p : primes) {
      ll prev = (A / p) * p;
      for (ll cur = prev + p; cur <= B; cur += p) {
        ll i = prev - A;
        ll j = cur - A;
        if (0 <= i && i < size) {
          auto ra = find(N, i);
          auto rb = find(N, j);
          if (ra != rb) join(N, ra, rb);
        }
        prev = cur;
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
