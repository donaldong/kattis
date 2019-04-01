#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

vi T, vis, skip, DP;
v2i G;
bool F = true;

void dfs(int n) {
  if (vis[n] == F) return;
  vis[n] = F;
  int t = 0;
  for (int nn : G[n]) {
    dfs(nn);
    t = max(t, DP[nn]);
  }
  if (!skip[n]) t += T[n];
  DP[n] = t;
#ifdef DEBUG
  printf("%d: %d\n", n, t);
#endif
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, k, p;
  cin >> n;
  T.resize(n), DP.resize(n), skip.assign(n, 0);
  G.resize(n), vis.assign(n, 0);
  for (auto &e : T) cin >> e;
  for (int i = 0; i < n; ++i) {
    cin >> k;
    while (k--) {
      cin >> p, --p;
      G[i].push_back(p);
    }
  }
  int res = INT_MAX;
  for (int i = 0; i < n; ++i) {
    skip[i] = true;
    dfs(n - 1), res = min(res, DP.back());
    skip[i] = false, F = !F;
  }
  printf("%d\n", res);
  return 0;
}
