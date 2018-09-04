#include <bits/stdc++.h>
using namespace std;

using Num = long long;
using Nums = vector<Num>;
using SumSet = unordered_set<Num>;

Num solve(Nums &N, int d) {
  Num res = 0;
  SumSet F;
  for (auto n : N) {
    SumSet B;
    for (auto s : F) {
      Num k = s + n;
      B.insert(k);
      if (k % d == 0) ++res;
    }
    B.insert(n);
    if (n % d == 0) ++res;
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
    for (auto &num : N) cin >> num;
    cout << solve(N, d) << endl;
  }
  return 0;
}
