#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using v2b = vector<vb>;
using vi = vector<int>;
using v2i = vector<vi>;
vi P;
v2i G, Gp;

bool bfs(int s, int t) {
  int cur;
  queue<int> Q;
  vb V(P.size(), false);
  Q.push(s);
  V[s] = true;
  while (!Q.empty()) {
    cur = Q.front(); Q.pop();
    for (size_t i = 0; i < V.size(); ++i) {
      if (V[i] || G[cur][i] <= 0) continue;
      V[i] = true;
      P[i] = cur;
      Q.push(i);
    }
  }
  return V[t];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m, s, t, a, b, c, f;
  cin >> n >> m >> s >> t;
  G.assign(n, vi(n, 0));
  Gp = G;
  P.assign(n, -1);
  while (m--) {
    cin >> a >> b >> c;
    G[a][b] = c;
  }
  int flow = 0;
  while (bfs(s, t)) {
    f = 1e9;
    for (b = t; b !=s;) {
      a = P[b];
      f = min(f, G[a][b]);
      b = a;
    }
    for (b = t; b !=s;) {
      a = P[b];
      G[a][b] -= f; G[b][a] += f;
      Gp[a][b] -= f; Gp[b][a] += f;
      b = a;
    }
    flow += f;
  }
  m = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (Gp[i][j] < 0) ++m;
    }
  }
  printf("%d %d %d\n", n, flow, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (Gp[i][j] < 0) printf("%d %d %d\n", i, j, -Gp[i][j]);
    }
  }
  return 0;
}
