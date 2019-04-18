#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int MAX_PRIME = sqrt(2.15e9) + 1;
vi prime(MAX_PRIME, 1), P;

bool solve(int n, int m) {
  if (!m) return false;
  for (int p : P) {
    int i = 0, j = n / p;
    while (m % p == 0) ++i, m /= p;
    if (!i) continue;
    while (j && i > 0) i -= j, j /= p;
    if (i > 0) return false;
  }
  return m == 1 || n >= m;
}

int main() {
  for (size_t i = 2; i < prime.size(); ++i) {
    if (!prime[i]) continue;
    P.push_back(i);
    for (size_t j = i * i; j < prime.size(); j += i) prime[j] = 0;
  }
  int n, m;
  while (cin >> n >> m) {
    printf("%d %s %d!\n", m, solve(n, m) ? "divides" : "does not divide", n);
  }
  return 0;
}
