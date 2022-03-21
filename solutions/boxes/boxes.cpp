#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

const int MAXN = 2e5;
const int MAX_LEVEL = ceil(log(MAXN) / log(2));
vi C, depth;
v2i T, P;

void dfs(int n) {
  for (int nn : T[n]) {
    depth[nn] = depth[n] + 1;
    P[nn][0] = n;
    dfs(nn);
    C[n] += C[nn];
  }
}

int lca(int a, int b) {
  int d = depth[b] - depth[a];
  if (d < 0) d *= -1, swap(a, b);
  for (int i = MAX_LEVEL; i--;) {
    if (d & (1 << i)) b = P[b][i];
  }
  for (int i = MAX_LEVEL; i--;) {
    if (P[a][i] != P[b][i]) a = P[a][i], b = P[b][i];
  }
  if (a == b) return a;
  return P[a][0];
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, q, k;
  cin >> n;
  T.resize(n + 1), C.assign(n + 1, 1), depth.assign(n + 1, 0);
  P.assign(n + 1, vi(MAX_LEVEL));
  for (int i = 0; i < n; ++i) {
    cin >> k;
    T[k].push_back(i + 1);
  }
  dfs(0);
  for (int j = 1; j < MAX_LEVEL; ++j) {
    for (int i = 0; i <= n; ++i) {
      P[i][j] = P[P[i][j - 1]][j - 1];
    }
  }
  cin >> q;
  while (q--) {
    cin >> m;
    vi M(m);
    for (int &e : M) cin >> e;
    int res = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i == j) continue;
        int &a = M[i], &b = M[j];
        if (a < 0 || b < 0) continue;
        int c = lca(a, b);
        if (c == b) swap(a, b);
        if (c == a) b = -1;
      }
    }
    for (int e : M) {
      if (e > 0) res += C[e];
    }
    printf("%d\n", res);
  }
  return 0;
}
