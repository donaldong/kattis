#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;

uint INF = -1;
int N, M;
// Grid
vector<vector<uint>> G;

void debug() {
  cout << endl;
  for (auto &row : G) {
    for (auto r : row) {
      cout << int(r) << " ";
    }
    cout << endl;
  }
}

void floyd_warshall() {
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (G[i][k] != INF && G[k][j] != INF) {
          G[i][j] = min(G[i][j], max(G[i][k], G[k][j]));
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;
  G = vector<vector<uint>>(N, vector<uint>(N, -1));
  for (int i = 0; i < M; ++i) {
    uint a, b, c;
    cin >> a >> b >> c;
    G[a][b] = min(G[a][b], c);
    G[b][a] = min(G[b][a], c);
  }
  floyd_warshall();
  uint res = 0;
  for (auto &row : G) for (auto &d : row) res = max(res, d);
  if (res == INF) cout << "IMPOSSIBLE" << endl;
  else cout << res << endl;
  return 0;
}
