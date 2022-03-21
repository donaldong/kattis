#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, a;
  cin >> n >> a;

  int N[n], k = 0;
  for (int &e : N) cin >> e;
  sort(N, N + n);
  for (int i = 0; i < n; ++i) {
    if (N[i] + 1 > a) break;
    a -= N[i] + 1, ++k;
  }
  printf("%d\n", k);
  return 0;
}
