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
using ti2 = tuple<int, int>;
using vb = vector<bool>;
using ld = double;
using vld = vector<ld>;
int INF = 1e9;

vi dijkstra(v2e &E, int cur, int exclude=-1) {
  int w;
  vi D(E.size(), INF);
  D[cur] = 0;
  priority_queue<ti2> Q;
  Q.emplace(0, cur);
  while (!Q.empty()) {
    tie(w, cur) = Q.top(); Q.pop();
    w *= -1;
    for (auto &e : E[cur]) {
      if (e.n == exclude) continue;
      int nw = e.w + w;
      if (nw < D[e.n]) {
        D[e.n] = nw;
        Q.emplace(-nw, e.n);
      }
    }
  }
  return D;
}

bool possible(v2e &E, int cur, ld lim, vld &R, vb &exits, int p) {
  vb V(E.size(), false);
  queue<int> Q;
  Q.push(cur);
  V[cur] = true;
  while (!Q.empty()) {
    cur = Q.front(); Q.pop();
    for (auto &e : E[cur]) {
      if (V[e.n] || R[e.n] > lim || e.n == p) continue;
      if (exits[e.n]) return true;
      V[e.n] = true;
      Q.push(e.n);
    }
  }
  return false;
}

int main() {
  int n, m, e, a, b, l, x, y;
  cin >> n >> m >> e;
  v2e E(n);
  while (m--) {
    cin >> a >> b >> l;
    --a, --b;
    E[a].emplace_back(b, l);
    E[b].emplace_back(a, l);
  }
  vb exits(n, false);
  while (e--) {
    cin >> a; --a;
    exits[a] = true;
  }
  cin >> x >> y;
  --x, --y;
  auto B = dijkstra(E, x, y);
  auto P = dijkstra(E, y, -1);
  // Distance Ratio for each node
  vld R(E.size(), -1);
  for (size_t i = 0; i < B.size(); ++i) {
    if (B[i] && P[i] && B[i] != INF && P[i] != INF) {
      R[i] = B[i];
      R[i] /= P[i];
    }
    //printf("node %d, B: %d, P: %d, Ratio: %.3Lf\n", i + 1, B[i], P[i], R[i]);
  }
  if (exits[x]) cout << 0 << endl;
  else {
    vld T = R;
    sort(T.begin(), T.end());
    bool f = false;
    for (size_t i = 0; i < T.size(); ++i) {
      if (T[i] < 0) continue;
      if (possible(E, x, T[i], R, exits, y)) {
        printf("%.9f\n", T[i] * 160.0);
        f = true;
        break;
      }
    }
    if (!f) cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
