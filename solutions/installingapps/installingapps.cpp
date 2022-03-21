#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, c;
  cin >> n >> c;
  int D[n], S[n], N[n];
  int INF = 1e9;
  v2i DP(n + 1, vi(n + 1, INF));
  for (int i = 0; i < n; ++i) N[i] = i, cin >> D[i] >> S[i];
  sort(N, N + n, [&](int a, int b) {
    return S[a] - D[a] < S[b] - D[b];
  });
  DP[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    int j = N[i - 1];
    for (int k = 1; k <= i; ++k) {
      int res = DP[i - 1][k];
      if (max(D[j], S[j]) + DP[i - 1][k - 1] <= c) {
        res = min(res, DP[i - 1][k - 1] + S[j]);
      }
      DP[i][k] = res;
#ifdef DEBUG
      printf("%d, %d: %d\n", i, k, res);
#endif
    }
  }
  vi ord;
  for (int i = n, k = n; i > 0 && k > 0; --i) {
    while (k && (DP[i][k - 1] == DP[i][k] || DP[i][k] == INF)) --k;
#ifdef DEBUG
      printf("[%d %d] %d vs %d\n", i, k, DP[i - 1][k], DP[i][k]);
#endif
    int j = N[i - 1];
    if (k && DP[i - 1][k - 1] + S[j] == DP[i][k]) {
      --k, ord.push_back(j);
    }
  }
  printf("%lu\n", ord.size());
  for (size_t i = ord.size(); i--;) printf("%d ", ord[i] + 1);
  printf("\n");
  return 0;
}
