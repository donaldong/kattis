#include <bits/stdc++.h>
using namespace std;

struct edge {
  int to, w;
};

typedef long long ll;
typedef vector<ll> vll;
typedef vector<edge> ve;
typedef vector<ve> v2e;
ll INF = 1e18;
v2e G;
vll D;

void bellman_ford(int s) {
  ll d;
  D.assign(G.size(), INF);
  D[s] = 0;
  for (size_t k = 1; k < G.size(); ++k) {
    for (size_t i = 0; i < G.size(); ++i) {
      if (D[i] == INF) continue;
      for (auto &e : G[i]) {
        if (e.to == i && e.w < 0) D[i] = -INF;
        d = D[i] + e.w;
        if (D[i] == -INF) D[e.to] = -INF;
        else if (d < D[e.to]) D[e.to] = d;
      }
    }
  }
  for (size_t k = 1; k < G.size(); ++k) for (size_t i = 0; i < G.size(); ++i) {
    if (D[i] == INF) continue;
    for (auto &e : G[i]) {
      d = D[i] + e.w;
      if (D[i] == -INF || d < D[e.to]) D[i] = D[e.to] = -INF;
    }
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, q, s, a, b, w;
  bool f = true;
  while (cin >> n >> m >> q >> s) {
    if (!n) break;
    if (!f) printf("\n");
    f = false;
    G.assign(n, ve());
    while (m--) {
      cin >> a >> b >> w;
      G[a].push_back({b, w});
    }
    bellman_ford(s);
    while (q--) {
      cin >> a;
      if (D[a] == -INF) printf("-Infinity\n");
      else if (D[a] == INF) printf("Impossible\n");
      else printf("%lld\n", D[a]);
    }
  }
  return 0;
}
