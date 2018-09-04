#include <bits/stdc++.h>
using namespace std;

using Num = long long;
using Nums = vector<Num>;
using vNums = vector<Nums>; 

Num solve(Nums &N, int d) {
  Num res = 0;
  vNums S(N.size(), Nums(N.size()));
  S[0][0] = N[0];
  if (N[0] % d == 0) ++res;
  for (size_t i = 1; i < N.size(); ++i) {
    S[i][i] = N[i];
    if (N[i] % d == 0) ++res;
    for (size_t j = 0; j < i; ++j) {
      Num k = S[j][i - 1] + N[i];
      if (k % d == 0) ++res;
      S[j][i] = k;
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
    for (auto &num : N) cin >> num;
    cout << solve(N, d) << endl;
  }
  return 0;
}
