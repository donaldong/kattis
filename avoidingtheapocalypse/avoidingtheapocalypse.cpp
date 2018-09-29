#include <bits/stdc++.h>
using namespace std;

struct edge {
  int n, from, a, b, flow;
  edge() {}
  edge(int n, int flow, int from, int a, int b) : 
    n(n), flow(flow), from(from), a(a), b(b) {}
};

using vb = vector<bool>;
using vi = vector<int>;
using v2i = vector<vi>;
using ve = vector<edge>;
using v2e = vector<ve>;
using ti2 = tuple<int, int>;
int INF = 1e9;
int MAX_T;

int index(int n, int t) {
  return n * MAX_T + t;
}

void connect(v2e &G, int a, int b, int flow) {
  int i = G[a].size(), j = G[b].size();
  G[a].emplace_back(b, flow, a, i, j);
  G[b].emplace_back(a, 0, b, j, i);
}

bool bfs(v2e &G, int cur, int t, ve &P) {
  vb V(G.size(), false);
  queue<int> Q;
  Q.push(cur);
  V[cur] = true;
  while (!Q.empty()) {
    cur = Q.front(); Q.pop();
    for (auto &e : G[cur]) {
      if (e.flow <= 0 || V[e.n]) continue;
      Q.push(e.n);
      P[e.n] = e;
      V[e.n] = true;
    }
  }
  return V[t];
}

int max_flow(v2e &G, int s, int t) {
  ve P(G.size());
  int res = 0, a, b;
  edge e;
  while (bfs(G, s, t, P)) {
    int flow = INF;
    for (b = t; b != s;) {
      e = P[b];
      a = e.from;
      flow = min(flow, G[a][e.a].flow);
      b = a;
    }
    for (b = t; b != s;) {
      e = P[b];
      a = e.from;
      G[a][e.a].flow -= flow;
      G[b][e.b].flow += flow;
      b = a;
    }
    res += flow;
  }
  return res;
}

int main() {
  int T, n, i, j, g, s, m, x, r, a, b, p, t;
  cin >> T;
  while (T--) {
    cin >> n >> i >> g >> s >> m; --i;
    MAX_T = s + 1;
    v2e G(n * MAX_T + 2);
    int sink = G.size() - 2, target = G.size() - 1;
    connect(G, sink, index(i, 0), g);
    while (m--) {
      cin >> a;
      --a;
      for (i = 0; i < MAX_T; ++i) {
        connect(G, index(a, i), target, INF);
      }
    }
    cin >> r;
    while (r--) {
      cin >> a >> b >> p >> t;
      --a, --b;
      for (i = 0; (j = i + t) < MAX_T; ++i) {
        connect(G, index(a, i), index(b, j), p);
      }
    }
    for (i = 0; i < n; ++i) for (t = 0; t < s; ++t) {
      connect(G, index(i, t), index(i, t + 1), INF);
    }
    printf("%d\n", max_flow(G, sink, target));
  }
  return 0;
}
