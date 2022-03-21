#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int t, n;
  cin >> t >> n;
  int tot = 0;
  vi V(n + 1), res(n + 1);
  for (int i = 1; i <= n; ++i) cin >> V[i], tot += V[i];
  v2i DP(n + 1, vi(t + 1, tot));
  for (int i = 1; i <= n; ++i) {
    for (int j = V[i]; j <= t; ++j) {
      DP[i][j] = min(DP[i - 1][j], DP[i - 1][j - V[i]] - V[i]);
      DP[i][j] = min(DP[i][j], DP[i][j - 1]);
    }
  }
  vi used, not_used;
  for (int i = n, j = t; i >= 1; --i) {
    while (DP[i][j] == DP[i][j - 1]) --j;
    if (DP[i][j] == DP[i - 1][j]) not_used.push_back(i);
    else used.push_back(i), j -= V[i];
  }

  reverse(used.begin(), used.end());
  reverse(not_used.begin(), not_used.end());
  t = 0;
  for (int i : used) res[i] = t, t += V[i];
  t = 0;
  for (int i : not_used) res[i] = t, t += V[i];
  for (int i = 1; i <= n; ++i) printf("%d ", res[i]);
  printf("\n");
  return 0;
}
