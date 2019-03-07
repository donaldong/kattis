#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using v2i = vector<vi>;
using hmap = unordered_map<int, int>;
using vhmap = vector<hmap>;

hmap tot;
vi N;
vhmap F;

void fact(int n, int i) {
  while (n % 2 == 0) {
    ++F[i][2], ++tot[2];
    n /= 2;
  }
  for (ll j = 3; j * j <= n; j += 2) {
    while (n % j == 0) {
      ++F[i][j], ++tot[j];
      n /= j;
    }
  }
  if (n != 1) ++F[i][n], ++tot[n];
}


int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  N.resize(n), F.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> N[i];
    fact(N[i], i);
  }
  int moves = 0, gcd = 1;
  for (auto &e : tot) {
    int k = e.first, v = e.second, r = v % n, b = v / n;
#ifdef DEBUG
    printf("[%d: %d] remain: %d, base: %d\n", k, v, r, b);
#endif
    gcd *= pow(k, b);
    for (int i = 0; i < n; ++i) {
      int d = F[i][k] - b;
#ifdef DEBUG
    printf("%d has %d extra\n", N[i], d);
#endif
      if (d <= 0) continue;
      if (d >= r) {
#ifdef DEBUG
        printf("+ %d\n", d - r);
#endif
        moves += d - r;
        r = 0;
      } else {
        r -= d;
      }
    }
  }
  printf("%d %d\n", gcd, moves);
  return 0;
}
