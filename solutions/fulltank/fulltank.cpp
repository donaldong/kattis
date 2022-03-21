#include <bits/stdc++.h>
using namespace std;

struct edge {
  // next node, weight
  int n, w;
  edge() {}
  edge(int n, int w) : n(n), w(w) {}
};

using vi = vector<int>;
using v2i = vector<vi>;
using ve = vector<edge>;
using v2e = vector<ve>;
int INF = 1e9;

void debug(v2i &T) {
  cout << endl;
  for (auto &row : T) {
    for (auto &cell : row) {
      if (cell == INF) cout << "INF ";
      else cout << cell << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int dijkstra(v2e &E, vi &P, int c, int cur, int dest) {
  int w, f, k, nw;
  v2i T(E.size(), vi(c + 1, INF));
  priority_queue<tuple<int, int, int>> Q;
  Q.emplace(0, 0, cur);
  T[cur][0] = 0;
  while (!Q.empty()) {
    tie(w, f, cur) = Q.top(); Q.pop();
    w *= -1;
    nw = T[cur][f] + P[cur];
    k = f + 1;
    if (f < c && nw < T[cur][k]) {
      T[cur][k] = nw;
      Q.emplace(-nw, k, cur);
    }
    for (auto &e : E[cur]) {
      k = f - e.w;
      if (k < 0) continue;
      if (T[cur][f] < T[e.n][k]) {
        T[e.n][k] = T[cur][f]; 
        if (e.n != dest) Q.emplace(-T[cur][f], k, e.n);
      }
    }
  }
  return T[dest][0];
}

int main() {
  int n, m, q, u, v, d, c;
  cin >> n >> m;
  // Prices
  vi P(n);
  // Edge List
  v2e E(n);
  for (auto &p : P) cin >> p;
  while (m--) {
    cin >> u >> v >> d;
    E[u].emplace_back(v, d);
    E[v].emplace_back(u, d);
  }
  cin >> q;
  while (q--) {
    cin >> c >> u >> v;
    int res = dijkstra(E, P, c, u, v);
    if (res == INF) cout << "impossible" << endl;
    else cout << res << endl;
  }
  return 0;
}
