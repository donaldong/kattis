#include <bits/stdc++.h>
using namespace std;

using Num = int;
using Nums = vector<Num>;
using SumMap = unordered_map<Num, Num>;

Num solve(Nums &N, int d) {
  Num res = 0;
  for (size_t i = 0; i < N.size(); ++i) {
    Num sum = N[i];
    if (!N[i]) ++res;
    for (size_t j = i + 1; j < N.size(); ++j) {
      sum += i;
      sum %= d;
      if (!sum) ++res;
    }
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

