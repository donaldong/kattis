#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using vull = vector<ull>;

ull MAX_F = 1e18;
vull F;

char solve(ull n, ull k) {
  if (n == 1) return 'N';
  if (n == 2) return 'A';
  if (k <= F[n - 2]) return solve(n - 2, k);
  return solve(n - 1, k - F[n - 2]);
}

int main() {
  ull n, k;
  cin >> n >> k;
  F = vull(3, 1);
  for (ull i = 0; i < n; ++i) {
    size_t k = F.size() - 1;
    if (F[k - 1] > MAX_F) break;
    ull cur = F[k] + F[k - 1];
    F.push_back(cur);
  }
  while (n >= F.size()) n -= 2;
  cout << solve(n, k) << endl;
  return 0;
}
