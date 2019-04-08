#include <bits/stdc++.h>
using namespace std;

typedef vector<uint> vi;
typedef vector<vi> v2i;
typedef tuple<uint, uint, uint> tup;

struct edge {
  uint to, w;
};

v2i F;
vector<vector<edge>> G;

uint dijkstra(uint s, uint t) {
  v2i D(F.size(), vi(2, -1));
  priority_queue<tup, vector<tup>, greater<tup>> Q;
  D[s][0] = 0, Q.emplace(0, s, 0);
  uint d, nd, f;
  while (!Q.empty()) {
    tie(d, s, f) = Q.top(), Q.pop();
    if (d > D[s][f]) continue;
    for (auto &e : G[s]) {
      nd = d + e.w;
      if (nd < D[e.to][f]) D[e.to][f] = nd, Q.emplace(nd, e.to, f);
    }
    if (!f) for (uint n : F[s]) {
      if (d < D[n][1]) D[n][1] = d, Q.emplace(d, n, 1);
    }
  }
  return min(D[t][0], D[t][1]);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  uint n, m, f, s, t, a, b, c;
  cin >> n >> m >> f >> s >> t;
  G.resize(n), F.resize(n);
  while (m--) {
    cin >> a >> b >> c;
    G[a].push_back({b, c}), G[b].push_back({a, c});
  }
  while (f--) {
    cin >> a >> b;
    F[a].push_back(b);
  }
  printf("%u\n", dijkstra(s, t));
  return 0;
}
