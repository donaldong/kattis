#include <bits/stdc++.h>
using namespace std;

const int MAX_W = 6301;
int DP[21][MAX_W];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    if (!n) break;
    int V[n + 1], tot = 0;
    for (int i = 1; i <= n; ++i) cin >> V[i], tot += V[i];
    for (int i = 0; i < MAX_W; ++i) DP[0][i] = tot;
    for (int i = 1; i <= n; ++i) DP[i][0] = tot;

    for (int i = 1; i <= n; ++i) for (int w = 1; w < MAX_W; ++w) {
      DP[i][w] = min(DP[i][w - 1], DP[i - 1][w]);
      if (w >= V[i]) {
        int sel = DP[i - 1][w - V[i]] - 2 * V[i];
        if (sel >= 0) DP[i][w] = min(DP[i][w], sel);
      }
    }

    int s = 0, w = MAX_W - 1;
    for (int i = n; i > 0; --i) {
      while (DP[i][w] == DP[i][w - 1]) --w;
      if (w < V[i] || DP[i][w] == DP[i - 1][w]) continue;
      s += V[i], w -= V[i];
    }
    printf("%d %d\n", tot - s, s);
  }

  return 0;
};
