#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using vi = vector<uint>;
using v2i = vector<vi>;
using ll = long long;
using vll = vector<ll>;
using ti2 = tuple<ll, uint>;
using vb = vector<bool>;

ll INF = 1e18;

struct edge;

using ve = vector<edge>;
using v2e = vector<ve>;

struct edge {
  uint n, t;
  edge() {}
  edge(uint n, uint t) : n(n), t(t) {}
};

ll dijkstra(v2e &G, uint e_cap) {
  priority_queue<ti2> Q;
  vll D(G.size(), INF);
  D[0] = 0;
  Q.emplace(0, 0);
  ll w;
  uint n;
  while (!Q.empty()) {
    tie(w, n) = Q.top(), Q.pop();
    for (auto &e : G[n]) {
      if (e.t <= e_cap) {
        ll nw = -w + e.t;
        if (nw < D[e.n]) {
          D[e.n] = nw;
          Q.emplace(-nw, e.n);
        }
      }
    }
  }
  return D.back();
}

int main() {
  int n, m, x, a, b;
  cin >> n >> m >> x;
  v2e G(n);
  vi T(m);
  for (auto &t : T) {
    cin >> a >> b >> t;
    --a, --b;
    G[a].push_back(edge(b, t));
    G[b].push_back(edge(a, t));
  }
  ll d = dijkstra(G, 1e9);
  d *= 100 + x;
  d /= 100;
  sort(T.begin(), T.end());
  auto end = unique(T.begin(), T.end());
  int lo = 0, hi = end - T.begin() - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (dijkstra(G, T[mid]) > d) lo = mid + 1;
    else hi = mid;
  }
  cout << T[lo] << endl;
  return 0;
}
