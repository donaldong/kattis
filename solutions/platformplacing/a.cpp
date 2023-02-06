/**
 * @date        2023-02-05
 * @tags        greedy
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n,s,k;
  cin >> n >> s >> k;
  vector<ll> X(n), L(n, s*2);
  for (ll& x : X) cin >> x, x *= 2;
  sort(X.begin(), X.end());
  auto left = [&](int i) -> ll{
    if (i == 0) return -1e9;
    auto x = X[i-1];
    return x+L[i-1]/2;
  };
  auto right = [&](int i) -> ll {
    if (i+1 == n) return 1e9;
    auto x = X[i+1];
    return x-L[i+1]/2;
  };
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    ll l = left(i), r = right(i);
    ll half = min({X[i]-l, r-X[i], (ll)k});
    if (half < s) {
      cout << -1 << endl;
      return 0;
    }
    L[i] = 2*half;
    res += half;
  }
  cout << res << endl;
  return 0;
}
