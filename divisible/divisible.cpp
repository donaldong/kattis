#include <bits/stdc++.h>
using namespace std;

using Num = int;
using Nums = vector<Num>;

Num solve(Nums &N, int d) {
  Num res = 0;
  Nums F(d, 0), B(d, 0);
  for (Num num : N) {
    if (!num) ++res;
    fill(B.begin(), B.end(), 0);
    for (size_t i = 0; i < F.size(); ++i) {
      if (!F[i]) continue;
      Num k = (i + num) % d;
      if (!k) res += F[i];
      B[k] += F[i];
    }
    ++B[num];
    swap(F, B);
  }
  return res;
}

int main() {
  int c, d, n;
  cin >> c;
  while (c--) {
    cin >> d >> n;
    Nums N(n);
    for (auto &num : N) {
      cin >> num;
      num %= d;
    }
    cout << solve(N, d) << endl;
  }
  return 0;
}
