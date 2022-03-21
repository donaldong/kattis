#include <bits/stdc++.h>
using namespace std;

int dfs(int n, int m, long long a) {
#ifdef DEBUG
  printf("dfs(n=%d, m=%d, a=%lld)\n", n, m, a);
#endif
  if (n < m) swap(n, m);
  if (a % n == 0 || a % m == 0) return 1;

  for (int k = 1; k <= m; ++k) {
    if (a % k) continue;
    long long k2 = a/k;
    if (k2 <= n) return 2;
  }

  long long a2 = (long long)n*m-a;
  for (int k = 1; k <= m; ++k) {
    if (a2 % k) continue;
    long long k2 = a2/k;
    if (k2 <= n) return 2;
  }

  long long c = a/n;
  return 1+dfs(n,m-c,a-n*c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long N,M,A;
  cin >>N>>M>>A;
  cout << dfs(N,M,A) << endl;
  return 0;
}
