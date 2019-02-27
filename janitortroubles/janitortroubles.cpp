#include <bits/stdc++.h>
using namespace std;

double area(int S[4]) {
  // Brahmagupta's Formula
  double s = 0;
  for (int i = 0; i < 4; ++i) s += S[i];
  s /= 2;
  double res = 1.0;
  for (int i = 0; i < 4; ++i) res *= s - S[i];
  return sqrt(res);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int S[4];
  double res = 0;
  for (int i = 0; i < 4; ++i) cin >> S[i];
  sort(S, S + 4);
  do {
    res = max(res, area(S));
  } while (next_permutation(S, S + 4));
  printf("%.7lf\n", res);
  return 0;
}
