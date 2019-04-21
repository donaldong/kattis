#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int MOD = 360e3;

int kmp(vi &S, vi &P) {
  vi lps(P.size(), 0);
  int i = 0, j = 1;
  while (j < P.size()) {
    if (P[i] == P[j]) lps[j] = ++i, ++j;
    else if (i) i = lps[i - 1];
    else ++j;
  }
  i = 0, j = 0;
  while (i < S.size()) {
    while (i < S.size() && j < P.size() && S[i] == P[j]) ++i, ++j;
    if (j == P.size()) return i - P.size();
    if (j) j = lps[j - 1];
    else ++i;
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vi A(n), B(n), X(2 * n), Y(n);
  for (auto &e : A) cin >> e;
  for (auto &e : B) cin >> e;
  sort(A.begin(), A.end()), sort(B.begin(), B.end());
#ifdef DEBUG
  printf("A: ");
  for (int i : A) printf("%d ", i);
  printf("\nB: ");
  for (int i : B) printf("%d ", i);
  printf("\n");
#endif
  for (int i = 0; i < n; ++i) {
    X[i] = X[i + n] = (A[(i + 1) % n] - A[i] + MOD) % MOD;
    Y[i] = (B[(i + 1) % n] - B[i] + MOD) % MOD;
  }
#ifdef DEBUG
  printf("X: ");
  for (int i : X) printf("%d ", i);
  printf("\nY: ");
  for (int i : Y) printf("%d ", i);
  printf("\n");
#endif
  printf("%s\n", kmp(X, Y) >= 0 ? "possible" : "impossible");
  return 0;
}
