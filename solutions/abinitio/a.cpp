/**
 * @date        2022-03-29
 * @tags        graph, data structure
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
constexpr int MAXV = 4000;
using EdgeSet = vector<array<bool, MAXV>>; // unordered_set is too slow
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  array<EdgeSet, 4> E;
  for (auto& e : E) e.resize(MAXV);
  auto addEdge = [&](int a, int b) {
    E[0][a][b] = E[1][b][a] = true;
    E[2][a][b] = E[3][b][a] = false;
  };
  auto removeEdge = [&](int a, int b) {
    E[0][a][b] = E[1][b][a] = false;
    E[2][a][b] = E[3][b][a] = true;
  };
  int v,e,q,a,b,c;
  cin >> v >> e >> q;
  for (int i = 2; i < 4; ++i) for (int j = 0; j < v; ++j) {
    for (int k = 0; k < v; ++k)  {
      if (j == k) continue;
      E[i][j][k] = true;
    }
  }
  while (e--) {
    cin >> a >> b;
    addEdge(a, b);
  }
  while (q--) {
    cin >> c;
    switch (c) {
    case 1:
      for (int i = 0; i < v; ++i) {
        E[2][i][v] = E[3][v][i] = true;
        E[2][v][i] = E[3][i][v] = true;
      }
      ++v;
      break;
    case 2:
      cin >> a >> b;
      addEdge(a, b);
      break;
    case 3:
      cin >> a;
      for (int b = 0; b < v; ++b) { // handle edge out
        if (!E[0][a][b]) continue;
        E[2][a][b] = E[3][b][a] = true;
        E[1][b][a] = E[0][a][b] = false;
      }
      for (int b = 0; b < v; ++b) { // handle edge in
        if (!E[1][a][b]) continue;
        E[2][b][a] = E[3][a][b] = true;
        E[0][b][a] = E[1][a][b] = false;
      }
      break;
    case 4:
      cin >> a >> b;
      removeEdge(a, b);
      break;
    case 5:
      swap(E[0], E[1]), swap(E[2], E[3]);
      break;
    case 6:
      swap(E[0], E[2]), swap(E[1], E[3]);
      break;
    }
  }
  printf("%d\n", v);
  constexpr int m = 1e9+7;
  for (int i = 0; i < v; ++i) {
    long long h = 0, p = 1;
    int cnt = 0;
    for (int n = 0; n < v; ++n) {
      if (!E[0][i][n]) continue;
      h += p * n, p *= 7;
      h %= m, p %= m;
      ++cnt;
    }
    printf("%d %lld\n", cnt, h);
  }
  return 0;
}
