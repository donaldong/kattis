#include <bits/stdc++.h>
using namespace std;

struct edge {
  uint to, flow, rev;
};

typedef vector<int> vi;
typedef vector<edge> ve;
typedef vector<ve> v2e;

int T;
vi vis, lvl, E, res;
v2e G;

bool bfs(int n) {
  queue<int> Q;
  lvl.assign(G.size(), 0);
  lvl[n] = 1, Q.push(n);
  while (!Q.empty()) {
    n = Q.front(), Q.pop();
    for (auto &e : G[n]) {
      if (lvl[e.to] || !e.flow) continue;
      lvl[e.to] = lvl[n] + 1;
      Q.push(e.to);
    }
  }
  return lvl[T];
}

uint dfs(int n, uint flow) {
  if (n == T) return flow;
  for (; E[n] < G[n].size(); ++E[n]) {
    auto &e = G[n][E[n]];
    if (!e.flow || lvl[n] + 1 != lvl[e.to]) continue;
    uint f = dfs(e.to, min(flow, e.flow));
    if (!f) continue;
    auto &rev = G[e.to][e.rev];
    e.flow -= f, rev.flow += f;
    return f;
  }
  return 0;
}

void dfs2(int n) {
  if (vis[n]) return;
  vis[n] = true, res.push_back(n);
  for (auto &e : G[n]) {
    if (e.flow) dfs2(e.to);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  uint n, m, s, a, b, w;
  cin >> n >> m >> s >> T;
  G.resize(n), res.reserve(n);
  while (m--) {
    cin >> a >> b >> w;
    uint i = G[a].size(), j = G[b].size();
    G[a].push_back({b, w, j}), G[b].push_back({a, 0, i});
  }
  while (bfs(s)) {
    E.assign(G.size(), 0);
    while (dfs(s, -1));
  }
  vis.assign(G.size(), 0);
  dfs2(s);
  printf("%lu\n", res.size());
  for (int i : res) printf("%d\n", i);
  return 0;
}
