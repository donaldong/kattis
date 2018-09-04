#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using vull = vector<ull>;

ull MAX_F = 1e18;
vull F;

char solve(ull n, ull k) {
  if (n == 0) return 'N';
  if (n == 1) return 'A';
  if (k <= F[n - 2]) return solve(n - 2, k);
  return solve(n - 1, k - F[n - 2]);
}

int main() {
  ull n, k;
  cin >> n >> k;
  F = vull(2, 1);
  for (ull i = 0; i < n; ++i) {
    size_t k = F.size() - 1;
    ull cur = F[k] + F[k - 1];
    if (cur < MAX_F) F.push_back(cur);
  }
  while (n >= F.size()) n -= 2;
  cout << solve(n, k) << endl;
  return 0;
}
