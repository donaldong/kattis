#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

int M;
vi C;
v2i DP;

int dfs(int n, int m) {
  if (n >= C.size()) return 0;
  if (DP[n][m] != -1) return DP[n][m];
  int res = dfs(n + 1, n ? m * 2 / 3 : m); // eat n + 1
  res = max(res, dfs(n + 2, m)); // skip n + 1
  res = max(res, dfs(n + 3, M)); // skip n + 1, n + 2
  res += min(C[n], m);
  DP[n][m] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n >> M;
  C.resize(n + 1), DP.resize(n + 1, vi(M + 1, -1));
  for (int i = 1; i <= n; ++i) cin >> C[i];
  printf("%d\n", dfs(0, M));
  return 0;
}
