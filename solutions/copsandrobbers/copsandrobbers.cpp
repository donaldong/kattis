#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using vi = vector<int>;
using v2i = vector<vi>;
using vs = vector<string>;
int INF = 1e9;
int n_row, n_col, n_cost;
vs G;
vi C;
int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

int index(int r, int c) {
  if (r < 0 || r >= n_row ||
    c < 0 || c >= n_col) return -1;
  return c + r * n_col;
}

int cost(int r, int c) {
  char k = G[r][c] - 'a';
  if (0 <= k && k < 26) return C[k];
  return INF;
}

void find_src(const vs &G, int &r, int &c) {
  for (r = 0; r < n_row; ++r)
  for (c = 0; c < n_col; ++c)
  if (G[r][c] == 'B') return;
}

bool bfs(const v2i &RG, int s, vi &P) {
  vb vis(RG.size(), false);
  queue<int> Q;
  Q.push(s);
  vis[s] = true;
  while (!Q.empty()) {
    int a = Q.front(); Q.pop();
    for (size_t b = 0; b < RG.size(); ++b) {
      if (vis[b] || RG[a][b] <= 0) continue;
      vis[b] = true;
      P[b] = a;
      Q.push(b);
    }
  }
  return vis.back();
}

int min_cut(v2i &RG, int src) {
  int res = 0, a, b, flow, sink = RG.size() - 1;
  vi P(RG.size(), -1);
  while (bfs(RG, src, P)) {
    flow = INF;
    for (b = sink; b != src; b = a) {
      a = P[b];
      flow = min(flow, RG[a][b]);
    }
    if (flow == INF) return -1;
    for (b = sink; b != src; b = a) {
      a = P[b];
      if (RG[a][b] != INF) RG[a][b] -= flow;
      if (RG[b][a] != INF) RG[b][a] += flow;
    }
    res += flow;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n_col >> n_row >> n_cost;
  G.resize(n_row); C.resize(n_cost); for (int i = 0; i < n_row; ++i) cin >> G[i];
  for (int i = 0; i < n_cost; ++i) cin >> C[i];

  int _size = n_row * n_col, size = 2 * _size + 1, r_src, c_src;
  v2i ris_graph(size, vi(size, 0));
  for (int r = 0; r < n_row; ++r) for (int c = 0; c < n_col; ++c) {
    int a = index(r, c), a_ = a + _size;
    ris_graph[a][a_] = cost(r, c);
    for (int i = 0; i < 4; ++i) {
      int nr = r + DR[i], nc = c + DC[i];
      int b = index(nr, nc);
      if (b < 0) ris_graph[a_][size - 1] = INF;
      else ris_graph[a_][b] = INF;
    }
  }
  find_src(G, r_src, c_src);

  printf("%d\n", min_cut(ris_graph, index(r_src, c_src)));
  return 0;
}
