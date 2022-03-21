#include <bits/stdc++.h>
using namespace std;
array<int,4> DR{0, 1};
array<int,4> DC{1, 0};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int R, C;
  cin >> R >> C;
  vector<vector<int>> G(R, vector<int>(C, INT_MAX));
  for (auto &row : G) for (auto &col : row) cin >> col;
  vector<vector<pair<int,int>>> adj(R*C);
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      int i = c+r*C;
      for (int dir = 0; dir < 2; ++dir) {
        int r2 = r+DR[dir], c2 = c+DC[dir];
        if (r2 < 0 || r2 >= R || c2 < 0 || c2 >= C) continue;
        int j = c2+r2*C;
        adj[i].emplace_back(j, max(G[r2][c2]-G[r][c], 0));
        adj[j].emplace_back(i, max(G[r][c]-G[r2][c2], 0));
      }
    }
  }
  using Pair = pair<int,int>;
  priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
  pq.emplace(0, 0);
  vector<int> dist(R*C, INT_MAX);
  dist[0] = 0;
  while (!pq.empty()) {
    auto [d, i] = pq.top();
    pq.pop();
    if (d > dist[i]) continue;
#ifdef DEBUG
    printf("(d=%d, i=%d)\n", d, i);
#endif
    for (auto [j, w] : adj[i]) {
#ifdef DEBUG
    printf("%d: [j=%d, w=%d]\n", i, j, w);
#endif
      int d2 = max(d, w);
      if (dist[j] <= d2) continue;
      dist[j] = d2;
      pq.emplace(d2, j);
    }
  }
  cout << dist.back() << endl;
  return 0;
}
