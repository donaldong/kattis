#include <bits/stdc++.h>
using namespace std;

struct edge {
  int to, t, b;
};

typedef vector<edge> ve;
typedef vector<ve> v2e;
typedef vector<int> vi;
typedef vector<vi> v2i;

v2e G;
vi C;
v2i T, K;

vi dijkstra(int a) {
  int b, k, t, nt, t_wait, i;
  vi D(G.size(), INT_MAX);
  priority_queue<tuple<int, int>> Q;
  Q.emplace(0, a), D[a] = 0;
  while (!Q.empty()) {
    tie(t, a) = Q.top(), t *= -1, Q.pop();
    if (t > D[a]) continue;
    for (auto &e : G[a]) {
      i = K[e.b][a];
      t_wait = t - T[e.b][i];
      if (t_wait > 0) {
        k = t_wait / C[e.b];
        if (t_wait % C[e.b]) ++k;
        nt = T[e.b][i] + k * C[e.b] + e.t;
      } else {
        k = -t_wait / C[e.b];
        nt = T[e.b][i] - k * C[e.b] + e.t;
      }
      if (nt >= D[e.to]) continue;
      Q.emplace(-nt, e.to), D[e.to] = nt;
    }
  }
#ifdef DEBUG
  for (int d : D) {
    if (d == INT_MAX) cout << "INF" << "\t";
    else cout << d << "\t";
  }
  cout << endl << endl;
#endif
  return D;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int b, n, x, y, k, t;
  cin >> b >> n >> x >> y;
  G.resize(b), T.resize(n), C.resize(n), K.assign(n, vi(b));
  for (int i = 0; i < n; ++i) {
    cin >> C[i] >> k;
    vi S(k);
    T[i] = vi(k, 0);
    for (int j = 0; j < k; ++j) {
      cin >> S[j], K[i][S[j]] = j;
    }
    for (int j = 1; j < k; ++j) {
      cin >> t;
      G[S[j - 1]].push_back({S[j], t, i});
      T[i][j] = T[i][j - 1] + t;
    }
  }

  vi X = dijkstra(x), Y = dijkstra(y);
  int res = INT_MAX;
  for (int i = 0; i < b; ++i) res = min(res, max(X[i], Y[i]));
  if (res != INT_MAX) printf("%d\n", res);
  else printf("NO COFFEE FOR YOU\n");
  return 0;
}
