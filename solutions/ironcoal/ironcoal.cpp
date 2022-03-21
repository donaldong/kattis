#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;
int INF = 1e6;
v2i G, GT, DP;
vi vis;

void dfs(int b) {
  vis[b] = 1;
  for (int c : G[b]) {
    if (vis[c] == 1) continue;
    dfs(c);
  }
  for (int a : GT[b]) {
    for (int i = 0; i < 2; ++i) {
      DP[a][i] = min(DP[a][i], DP[b][i] + 1);
#ifdef DEBUG
      printf("update %d from %d: DP[%d][%d] = %d\n",
        a, b, a, i, DP[a][i]);
#endif
    }
    DP[a][2] = min(DP[a][2], DP[b][2] + 1);
    DP[a][2] = min(DP[a][2], DP[b][0] + DP[b][1] + 1);
  }
#ifdef DEBUG
  printf("resolve %d: %d %d %d\n", b, DP[b][0], DP[b][1], DP[b][2]);
#endif
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, k, a, b, res;
  cin >> n >> m >> k;
  G.resize(n + 1), GT.resize(n + 1);
  DP.assign(n + 1, vi(3, INF));
  while (m--) {
    cin >> a;
    DP[a][0] = 0;
  }
  while (k--) {
    cin >> a;
    DP[a][1] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a;
    while (a--) {
      cin >> b;
      G[i].push_back(b);
      GT[b].push_back(i);
    }
  }
  for (int i = 0; i < 10; ++i) {
    vis.assign(n + 1, 0);
    dfs(1);
  }
  res = min(DP[1][2], DP[1][0] + DP[1][1]);
  if (res >= INF) printf("impossible\n");
  else printf("%d\n", res);
  return 0;
}
