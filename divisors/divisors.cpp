#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> v2i;

int MAXN = 432;

int main() {
  v2i F(MAXN, vi(MAXN, 0));
  for (int i = 2; i < MAXN; ++i) {
    F[i] = F[i - 1];
    int n = i;
    while (n % 2 == 0) n /= 2, ++F[i][2];
    for (int j = 3; j * j <= n; j += 2) {
      while (n % j == 0) n /= j, ++F[i][j];
    }
    if (n > 1) ++F[i][n];
  }

  ios::sync_with_stdio(0), cin.tie(0);
  int n, k;
  while (cin >> n >> k) {
    vi V = F[n];
    for (int i = 0; i < MAXN; ++i) {
      V[i] -= F[k][i] + F[n - k][i];
    }
    ull res = 1;
    for (int i = 0; i < MAXN; ++i) if (V[i]) res *= V[i] + 1;
    printf("%llu\n", res);
  }
  return 0;
}
