/**
 * @date        2022-03-23
 * @tags        grid, shortest path
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N, K, res = INT_MAX;
  cin >> N >> K;
  vector<vector<pair<int,int>>> P(K+1);
  vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
  for (int r = 0; r < N; ++r) for (int c = 0, v; c < N; ++c) {
    cin >> v;
    P[v].emplace_back(r,c);
    if (v == 1) {
      dist[r][c] = 0;
      if (K == 1) res = 0;
    }
  }
  for (int k = 2; k <= K; ++k) for (auto [r1, c1] : P[k]) {
    for (auto [r2, c2] : P[k-1]) {
      int d = dist[r2][c2];
      if (d == INT_MAX) continue;
      d += abs(r1-r2)+abs(c1-c2);
      if (k == K) res = min(d, res);
      dist[r1][c1] = min(dist[r1][c1], d);
    }
  }
  cout << (res == INT_MAX ? -1 : res) << endl;
  return 0;
}
