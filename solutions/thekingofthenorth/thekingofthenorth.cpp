#include <bits/stdc++.h>
using namespace std;

struct edge;
typedef vector<int> vi;
typedef vector<vi> v2i;
typedef vector<edge> ve;
typedef vector<ve> v2e;
int DR[] = {0, 0, -1, 1};
int DC[] = {-1, 1, 0, 0};

struct edge {
  int to, flow, rev;
};

int T, INF = 1e9;
v2e G;
vi lvl;

bool bfs(int n) {
  lvl.assign(G.size(), -1);
  queue<int> Q;
  Q.push(n), lvl[n] = 0;
  bool reached = false;
  while (!Q.empty()) {
    n = Q.front(), Q.pop();
    for (auto &e : G[n]) {
      if (lvl[e.to] >= 0 || !e.flow) continue;
      lvl[e.to] = lvl[n] + 1, Q.push(e.to);
    }
  }
  return lvl[T] >= 0;
}

int dfs(int n, int flow, vi &E) {
  if (n == T) return flow;
  for (; E[n] < G[n].size(); ++E[n]) {
    auto &e = G[n][E[n]];
    if (!e.flow || lvl[n] + 1 != lvl[e.to]) continue;
    int f = dfs(e.to, min(flow, e.flow), E);
    if (!f) continue;
    e.flow -= f, G[e.to][e.rev].flow += f;
    return f;
  }
  return 0;
}

long long max_flow(int s) {
  long long res = 0;
  while (bfs(s)) {
    int flow;
    vi E(G.size(), 0);
    while ((flow = dfs(s, INF, E))) res += flow;
  }
  return res;
}

void add_edge(int u, int v, int w) {
  int a = G[u].size(), b = G[v].size();
  G[u].push_back({v, w, b});
  G[v].push_back({u, 0, a});
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int R, C, r, c, w, a, b;
  cin >> R >> C;
  T = R * C * 2;
  G.resize(T + 1);
  auto index = [&](int i, int j) {
    return i * C + j;
  };
  for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {
    cin >> w;
    a = index(i, j), b = a + R * C;
    add_edge(a, b, w);
    for (int k = 0; k < 4; ++k) {
      r = i + DR[k], c = j + DC[k];
      if (r < 0 || c < 0 || r >= R || c >= C) add_edge(b, T, INF);
      else add_edge(b, index(r, c), INF);
    }
  }
  cin >> r >> c;
  printf("%lld\n", max_flow(index(r, c)));
  return 0;
}
