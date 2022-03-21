#include <bits/stdc++.h>
using namespace std;

struct edge {
  int to, w;
};

typedef vector<int> vi;
typedef vector<edge> ve;
typedef vector<ve> v2e;

int INF = INT_MAX;

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int p, t, a, b, l;
  cin >> p >> t;
  v2e G(p);
  while (t--) {
    cin >> a >> b >> l;
    G[a].push_back({b, l}), G[b].push_back({a, l});
  }

  int w, nw;
  vi D(p, INF);
  priority_queue<tuple<int, int>> Q;
  Q.emplace(0, 0), D[0] = 0;
  while (!Q.empty()) {
    tie(w, a) = Q.top(), Q.pop();
    w *= -1;
    for (auto &e : G[a]) {
      nw = w + e.w;
      if (nw >= D[e.to]) continue;
      D[e.to] = nw, Q.emplace(-nw, e.to);
    }
  }

  int res = 0;
  vi vis(p, 0);
  queue<int> Q2;
  Q2.push(p - 1), vis[p - 1] = 1;
  while (!Q2.empty()) {
    a = Q2.front(), Q2.pop();
    for (auto &e : G[a]) {
      if (D[e.to] + e.w != D[a]) continue;
      res += e.w;
      if (!vis[e.to]) Q2.push(e.to), vis[e.to] = true;
    }
  }

  printf("%d\n", res << 1);
  return 0;
}
