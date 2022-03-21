#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vb = vector<bool>;
int MAX = 1000;

int index(int diff) {
  return diff + MAX;
}

int solve(vi &N) {
  vb T(2 * MAX + 1, false);
  T[0] = true;
  for (auto n : N) {
    vb B = T;
    for (size_t i = 0; i < T.size(); ++i) {
      if (!T[i]) continue;
      int k = index(n + i - MAX);
      if (k >= 0 && k < T.size()) {
        B[k] = true;
      }
    }
    T = B;
  }
  int a = MAX, b = MAX;
  while (a > 0 && !T[a] && !T[b]) --a, ++b;
  if (T[b]) return b;
  return a;
}

int main() {
  int n;
  cin >> n;
  vi N(n);
  for (auto &e : N) cin >> e;
  cout << solve(N) << endl;
  return 0;
}
