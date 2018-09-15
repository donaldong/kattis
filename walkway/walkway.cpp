#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using ll = long long;
using ti2 = tuple<ll, int>;

int MAX_LENGTH = 1001;
ll INF = 1e18 + 7;

struct edge {
  int n;
  ll cost;
  edge() {}
  edge(int n, ll cost) : n(n), cost(cost) {}
};

using ve = vector<edge>;
using v2e = vector<ve>;

ll dijkstra(v2e &G, int src, int dest) {
  vector<ll> D(MAX_LENGTH, INF);
  priority_queue<ti2> Q;
  Q.emplace(0, src);
  D[src] = 0;
  ll w;
  int n;
  while (!Q.empty()) {
    tie(w, n) = Q.top(); Q.pop();
    w *= -1;
    for (auto &e : G[n]) {
      ll nw = w + e.cost;
      if (nw < D[e.n]) {
        D[e.n] = nw;
        Q.emplace(-nw, e.n);
      }
    }
  }
  return D[dest];
}

int main() {
  int n, a, b, h, w1, w2;
  while (cin >> n) {
    if (!n) break;
    v2e N(MAX_LENGTH);
    for (int i = 0; i < n; ++i) {
      cin >> a >> b >> h;
      ll cost = a + b;
      cost *= h;
      N[a].push_back(edge(b, cost));
      N[b].push_back(edge(a, cost));
    }
    cin >> w1 >> w2;
    ll res = dijkstra(N, w1, w2);
    printf("%lld.%02lld\n", res / 100, res % 100);
  }
  return 0;
}
