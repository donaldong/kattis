#include <bits/stdc++.h>
using namespace std;

typedef vector<uint> vi;
typedef vector<vi> v2i;
uint INF = -1;
uint n, q, s, POS_Q, POS_D, S, T, SIZE;
vi Q, C, lvl;
v2i added;

struct edge {
  uint flow, rev, to;
};

typedef vector<edge> ve;
typedef vector<ve> v2e;
v2e G;

void add_edge(uint a, uint b, uint f) {
  if (added[a][b]) return;
  added[a][b] = 1;
  uint r1 = G[a].size(), r2 = G[b].size();
  G[a].push_back({f, r2, b});
  G[b].push_back({0, r1, a});
}

bool bfs() {
  int a;
  lvl.assign(SIZE, INF);
  queue<int> Q;
  Q.push(S), lvl[S] = 0;
  while (!Q.empty()) {
    a = Q.front(), Q.pop();
    for (auto &e : G[a]) {
      if (!e.flow || lvl[e.to] != INF) continue;
      lvl[e.to] = lvl[a] + 1, Q.push(e.to);
    }
  }
  return lvl[T] != INF;
}

uint dfs(uint n, uint flow, vi &E) {
  if (n == T) return flow;
  for (; E[n] < G[n].size(); ++E[n]) {
    auto &e = G[n][E[n]];
    if (lvl[e.to] == lvl[n] + 1 && e.flow) {
      uint f = dfs(e.to, min(flow, e.flow), E);
      if (!f) continue;
      if (e.flow != INF) e.flow -= f;
      auto &rev_flow = G[e.to][e.rev].flow;
      if (rev_flow != INF) rev_flow += f;
      return f;
    }
  }
  return 0;
}

uint max_flow() {
  uint res = 0, flow;
  while (bfs()) {
    vi E(SIZE, 0);
    while ((flow = dfs(S, INF, E))) res += flow;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q >> s;
  Q.resize(s), C.resize(q);
  for (auto &e : Q) cin >> e, --e;
  for (auto &e : C) cin >> e;
  POS_Q = s * n, POS_D = POS_Q + q * n * 2;
  T = POS_D + n * 2, S = T + 1, SIZE = S + 1;
  G.resize(SIZE), added.assign(SIZE, vi(SIZE, 0));

  uint tot = 0, a;
  for (int i = 0; i < n; ++i) {
    int k = POS_D + i + n, l, d;
    cin >> d;
    add_edge(POS_D + i, k, d); // d start -> d end
    add_edge(k, T, INF); // d end -> target
    for (int j = 0; j < s; ++j) {
      cin >> a;
      tot += a, k = i * s + j, l = POS_Q + i * q + Q[j];
      add_edge(k, l, a); // sensor at t_i -> q_i start
      add_edge(S, k, INF); // source -> sensor at t_i
      add_edge(l, l + n * q, C[Q[j]]); // q_i start -> q_i end
      add_edge(l + n * q, POS_D + i, INF); // q_i end -> d start
    }
  }

  for (int i = 1; i < n; ++i) for (int j = 0; j < s; ++j) {
    // prev q end -> cur q start
    add_edge(
      POS_Q + (i - 1 + n) * q + Q[j],
      POS_Q + i * q + Q[j],
      INF);
  }
  
  printf("%s\n", max_flow() == tot ? "possible" : "impossible");
  return 0;
}
