/**
 * @date        2022-03-24
 * @tags        grid, shortest path
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
using Tuple = tuple<int,int,int>;
array<int,4> DR{0,0,-1,1};
array<int,4> DC{-1,1,0,0};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  vector<vector<int>> G(N, vector<int>(N, INT_MAX));
  auto dist = G;
  for (auto& row : G) for (auto& cell : row) cin >> cell;
  priority_queue<Tuple,vector<Tuple>,greater<Tuple>> pq;
  pq.emplace(0, 0, 0);
  while (!pq.empty()) {
    auto [d1, r1, c1] = pq.top(); pq.pop();
    if (d1 > dist[r1][c1]) continue;
    for (int i = 0; i < 4; ++i) {
      int r2 = r1+DR[i], c2 = c1+DC[i];
      if (r2 < 0 || r2 >= N || c2 < 0 || c2 >= N) continue;
      int d2 = max(d1, G[r2][c2]);
      if (d2 >= dist[r2][c2]) continue;
      dist[r2][c2] = d2;
      pq.emplace(d2, r2, c2);
    }
  }
  cout << dist[N-1][N-1] << endl;
  return 0;
}
