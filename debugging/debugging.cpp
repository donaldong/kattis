#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef vector<ull> vull;
vull DP;
ull R, P;

ull solve(int n) {
  if (DP[n] != -1) return DP[n];
  ull res = -1;
  for (int k = 1; k < n; ++k) {
    int lines = n / (k + 1);
    if (n % (k + 1)) ++lines;
    res = min(res, solve(lines) + k * P);
  }
  res += R;
  DP[n] = res;
#ifdef DEBUG
  printf("%d: %lld\n", n, res);
#endif
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ull n;
  cin >> n >> R >> P;
  DP.assign(n + 1, -1);
  DP[0] = DP[1] = 0;
  printf("%lld\n", solve(n));
  return 0;
}
