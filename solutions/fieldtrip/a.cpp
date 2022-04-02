/**
 * @date        2022-04-01
 * @tags        implementation
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n,a,b;
  cin >> n;
  ll tot = 0, s;
  vector<int> N(n);
  for (int& n : N) cin >> n, tot += n;
  auto possible = [&]() {
    if (tot % 3) return false;
    tot /= 3;
    for (a = 0, s = 0; a < n; ++a) {
      s += N[a];
      if (s == tot) break;
      if (s > tot) return false;
    }
    for (b = ++a, s = 0; b < n; ++b) {
      s += N[b];
      if (s == tot) break;
      if (s > tot) return false;
    }
    ++b;
    return 1 <= a && a < b && b < n;
  };
  if (possible()) cout << a << ' ' << b << endl;
  else cout << -1 << endl;
  return 0;
}
