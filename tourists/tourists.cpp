#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> v2i;

const int MAX_NODE = 2e5;
const int MAX_DEPTH = ceil(log(MAX_NODE) / log(2));
v2i G, P;
vi depth;

void dfs(int a, int b) {
  P[b][0] = a;
  depth[b] = depth[a] + 1;
  for (int c : G[b]) if (a != c) dfs(b, c);
}

int lca(int a, int b) {
  int d = depth[b] - depth[a], l = 0;
  if (d < 0) swap(a, b), d *= -1;
  for (int i = MAX_DEPTH; i--;) {
    if (d & (1 << i) ) b = P[b][i];
  }
  for (int i = MAX_DEPTH; i--;) {
    if (P[a][i] != P[b][i]) a = P[a][i], b = P[b][i];
  }
  if (a == b) return a;
  return P[a][0];
}

int path_length(int a, int b) {
  int c = lca(a, b);
#ifdef DEBUG
  printf("gcd(%d, %d) = %d : (%d) (%d)\n",
    a, b, c, depth[a] - depth[c],
    depth[b] - depth[c]);
#endif
  return depth[a] - depth[c] + depth[b] - depth[c] + 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, a, b;
  cin >> n;
  G.resize(n + 1), depth.resize(n + 1);
  P.assign(n + 1, vi(MAX_DEPTH));
  for (int i = 1; i < n; ++i) {
    cin >> a >> b;
    G[a].push_back(b), G[b].push_back(a);
  }
  dfs(1, 1);
  for (int j = 1; j < MAX_DEPTH; ++j) {
    for (int i = 1; i <= n; ++i) {
      P[i][j] = P[P[i][j - 1]][j - 1];
    }
  }

  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 2 * i; j <= n; j += i) {
      res += path_length(i, j);
    }
  }
  printf("%lld\n", res);
  return 0;
}
