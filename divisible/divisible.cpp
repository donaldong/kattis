#include <bits/stdc++.h>
using namespace std;

using Num = long long;
using Nums = vector<Num>;
using SumMap = unordered_map<Num, Num>;
using SumSet = unordered_set<Num>;

Num solve(Nums &N, int d) {
  SumMap M;
  SumSet F;
  for (auto n : N) {
    SumSet B;
    for (auto s : F) {
      Num k = s + n;
      B.insert(k);
      ++M[k];
    }
    B.insert(n);
    swap(F, B);
  }
  Num res = 0;
  for (auto &entry : M) {
    if (entry.first % d) continue;
    res += entry.second;
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
