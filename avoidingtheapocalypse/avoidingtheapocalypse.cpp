#include <bits/stdc++.h>
using namespace std;

struct edge {
  int n, p, t;
  edge() {}
  edge(int n, int p, int t) : n(n), p(p), t(t) {}
};

using vi = vector<int>;
using v2i = vector<vi>;
using ve = vector<edge>;
using v2e = vector<ve>;
using vb = vector<bool>;
using ti2 = tuple<int, int>;
int MAX_T = 101;

void debug(v2i &G) {
  cout << endl;
  for (auto &row : G) {
    for (auto &cell : row) {
      if (cell == INF) cout << "I ";
      else cout << cell << " "; 
    }
    cout << endl;
  }
  cout << endl;
}

v2i build(v2e &G, vb &F, int cur, int g, int s) {
  // sink, target, remaining time
  size_t size = n * MAX_T + 2; 
  int sink = size - 2, target = size - 1, rt;
  v2i RG(size, vi(size, 0));
  RG[sink][cur] = g;
  for (size_t i = 0; i < G.size(); ++i) {
    if (!F[i]) continue;
    for (size_t t = 0; t < MAX_T; ++t) {
      RG[index(i, t)][target] = INF;
    }
  }
  queue<tuple<int, int>> Q;
  RG[sink][index(cur, 0)] = g;
  Q.emplace(s, cur);
  while (!Q.empty()) {
    tie(rt, cur) = Q.front(); Q.pop(); 
  }
  for (size_t i = 0; i < G.size(); ++i) {
    for (auto &e : G[i]) {
      rt = s - D[i];
      printf("%d %d %d\n", i, e.n, rt);
      RG[i][e.n] = max((rt - e.t + 1) * e.p, 0);
    }
  }
  return RG;
}

bool bfs(v2i &G, int cur, int t, vi &P) {
  vb V(G.size(), false);
  queue<int> Q;
  Q.push(cur);
  V[cur] = true;
  while (!Q.empty()) {
    cur = Q.front(); Q.pop();
    for (size_t i = 0; i < G.size(); ++i) {
      if (G[cur][i] <= 0 || V[i]) continue;
      Q.push(i);
      P[i] = cur;
      V[i] = true;
    }
  }
  return V[t];
}

int max_flow(v2i &G, int s, int t) {
  vi P(G.size());
  int res = 0, a, b;
  while (bfs(G, s, t, P)) {
    int flow = INF;
    for (b = t; b != s;) {
      a = P[b];
      flow = min(flow, G[a][b]);
      b = a;
    }
    for (b = t; b != s;) {
      a = P[b];
      G[a][b] -= flow;
      G[b][a] += flow;
      b = a;
    }
    res += flow;
  }
  return res;
}

int main() {
  int T, n, i, g, s, m, x, r, a, b, p, t;
  cin >> T;
  while (T--) {
    cin >> n >> i >> g >> s >> m; --i;
    v2e G(n);
    vb F(n, false);
    while (m--) {
      cin >> a
      --a;
      F[a] = true;
    }
    cin >> r;
    while (r--) {
      cin >> a >> b >> p >> t;
      --a, --b;
      G[a].emplace_back(b, p, t);
    }
    // Residual Graph 
    v2i RG = build(G, F, i, g, s);
    printf("%d\n", max_flow(RG, n * MAX_T, n * MAX_T + 1));
    debug(RG);
  }
  return 0;
}
