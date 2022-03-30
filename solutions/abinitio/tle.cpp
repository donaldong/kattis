#include <bits/stdc++.h>
using namespace std;
using EdgeSet = array<unordered_set<int>,2000>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  vector<EdgeSet> E(4);
  auto addEdge = [&](int a, int b) {
    E[0][a].insert(b), E[1][b].insert(a);
    E[2][a].erase(b), E[3][b].erase(a);
  };
  auto addEdgeComplement = [&](int a, int b) {
    E[2][a].insert(b), E[3][b].insert(a);
  };
  auto removeEdge = [&](int a, int b) {
    E[0][a].erase(b),  E[1][b].erase(a);
    addEdgeComplement(a, b);
  };
  int v,e,q,a,b,c;
  cin >> v >> e >> q;
  for (int i = 0; i < v; ++i) for (int j = 0; j < v; ++j) {
    if (i == j) continue;
    addEdgeComplement(i, j), addEdgeComplement(j, i);
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
        addEdgeComplement(i, v), addEdgeComplement(v, i);
      }
      ++v;
      break;
    case 2:
      cin >> a >> b;
      addEdge(a, b);
      break;
    case 3:
      cin >> a;
      for (int b : E[0][a]) { // handle edge out
        E[2][a].insert(b), E[3][b].insert(a);
        E[1][b].erase(a);
      }
      E[0][a].clear();
      for (int b : E[1][a]) { // handle edge out
        E[2][b].insert(a), E[3][a].insert(b);
        E[0][b].erase(a);
      }
      E[1][a].clear();
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
    vector<int> N(E[0][i].begin(), E[0][i].end());
    sort(N.begin(), N.end());
    for (int n : N) {
      h += p * n, p *= 7;
      h %= m, p %= m;
    }
    printf("%lu %lld\n", N.size(), h);
  }
  return 0;
}

