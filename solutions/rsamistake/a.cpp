/**
 * @date        2022-09-26
 * @tags        math, number theory
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  long long a, b;
  cin >> a >> b;
  unordered_map<long long, int> factors;

  auto get_factors = [&](long long v) {
    while (v % 2 == 0) {
      v /= 2;
      ++factors[2];
    }
    for (long long f = 3; f * f <= v; f += 2) {
      while (v % f == 0) {
        v /= f;
        ++factors[f];
      }
    }
    if (v > 1) ++factors[v];
  };

  get_factors(a), get_factors(b);

  string res;
  for (auto [d, freq] : factors) {
    if (freq >= 2) {
      res = "no credit";
      break;
    }
  }
  if (res.empty()) {
    if (factors.size() > 2) res = "partial credit";
    else if (factors.size() == 2) res = "full credit";
    else res = "no credit";
  }
  cout << res << endl;
  return 0;
}
