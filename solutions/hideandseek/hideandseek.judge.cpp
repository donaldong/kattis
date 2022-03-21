#include <bits/stdc++.h>
using namespace std;

using ti = tuple<int, int>;
using vti = vector<ti>;
using v2ti = vector<vti>;
using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using v4i = vector<v3i>;
v2ti G;
// [node index, edge index, remaining time, on stem] 
int N, T;
//  => number of edges
v4i DP; 

void build(v2ti &R, int a, int b) {
  int c, w;
  for (size_t k = 0; k < G[b].size(); ++k) {
    tie(c, w) = G[b][k];
    if (c == a) continue;
    R[b].emplace_back(c, w);
    build(R, b, c);
  }
}

void dfs(int a, int b) {
  int c, w;
  for (int k = G[b].size(); k-- > 0;) {
    tie(c, w) = G[b][k];
    if (c == a) continue;
    dfs(b, c);
    int on, off, r;
    for (int t = 0; t < T; ++t) {
      on = DP[b][k + 1][t][1]; off = DP[b][k + 1][t][0];
      for (int tt = 0; tt <= t; ++tt) {
        r = t - tt - w;
        if (r < 0) break;
        on = max(on, DP[c][0][tt][1] + DP[b][k + 1][r][0] + 1);
        r -= w;
        if (r < 0) continue;
        on = max(on, DP[c][0][tt][0] + DP[b][k + 1][r][1] + 1);
        off = max(off, DP[c][0][tt][0] + DP[b][k + 1][r][0] + 1);
      }
      DP[b][k][t][1] = on, DP[b][k][t][0] = off;
#ifdef DEBUG
      printf(
        "%d => %d, k: %d, t: %d, on: %d, off: %d\n",
        b, c, k, t, on, off
      );
#endif
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int m, n, a, b, t;
  cin >> m >> n;
  G.resize(m);
  N = m, T = n + 1;
  DP.assign(N, v3i(N, v2i(T, vi(2, 0))));
  for (int i = 1; i < m; ++i) {
    cin >> a >> b >> t; 
    G[a].emplace_back(b, t);
    G[b].emplace_back(a, t);
  }
  v2ti G2(m);
  build(G2, 0, 0);
  G = G2;
  dfs(0, 0);
  cout << DP[0][0][n][1] << endl;
  return 0;
}
