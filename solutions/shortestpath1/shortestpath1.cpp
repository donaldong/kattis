#include <bits/stdc++.h>
using namespace std;

struct edge {
  int n, w;
  edge() {}
  edge(int n, int w) : n(n), w(w) {}
};

using ve = vector<edge>;
using v2e = vector<ve>;
using vi = vector<int>;
int INF = 1e9;

vi dijkstra(v2e &G, int cur) {
  int w, nw;
  vi D(G.size(), INF);
  priority_queue<tuple<uint, int>> Q;
  Q.emplace(0, cur);
  D[cur] = 0;
  while (!Q.empty()) {
    tie(w, cur) = Q.top(); Q.pop(); w *= -1;
    for (auto &e : G[cur]) {
      nw = w + e.w;
      if (nw < D[e.n]) {
        D[e.n] = nw;
        Q.emplace(-nw, e.n);
      }
    }
  }
  return D;
}

int main() {
  int n, m, q, s, a, b, w;
  bool f = true;
  while (cin >> n >> m >> q >> s) {
    if (!n && !m && !q && !s) break;
    v2e E(n);
    while (m--) {
      cin >> a >> b >> w;
      E[a].emplace_back(b, w);
    }
    auto D = dijkstra(E, s);
    if (!f) printf("\n");
    f = false;
    while (q--) {
      cin >> a;
      if (D[a] == INF) printf("Impossible\n"); 
      else printf("%u\n", D[a]);
    }
  }
  return 0;
}
