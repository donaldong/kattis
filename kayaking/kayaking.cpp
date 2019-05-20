#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool solve(vi &N, vi &S, int c, int v) {
  int i, j;
  for (i = 0; i < 3; ++i) {
    if (!N[i]) continue;
    --N[i];
    for (j = i; j < 3; ++j) {
      if (!N[j]) continue;
      --N[j];
      if (c * (S[i] + S[j]) >= v) return true;
      ++N[j];
    }
    ++N[i];
  }
#ifdef DEBUG
  printf("failed to reach v=%d when c=%d\n", v, c);
#endif
  return false;
}

bool possible(vi N, vi S, vi &C, int v) {
  for (int c : C) {
    if (!solve(N, S, c, v)) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int m = 0, s, lo = 0, hi = 2e8 + 1;
  vi N(3), S(3);
  for (int &n : N) cin >> n, m += n;
  for (int &s : S) cin >> s;
  vi C(m / 2);
  for (int &c : C) cin >> c;
  sort(C.begin(), C.end());
  while (lo + 1 < hi) {
    int mid = (lo + hi) >> 1;
    if (possible(N, S, C, mid)) lo = mid;
    else hi = mid;
  }
  printf("%d\n", lo);
  return 0;
}
