#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using vb = vector<bool>;
int INF = 1e9;

void floyd(v2i &G) {
  size_t size = G.size();
  for (size_t k = 0; k < size; ++k) {
    for (size_t i = 1; i < size; ++i) {
      if (G[i][k] == INF) continue;
      for (size_t j = 0; j < i; ++j) {
        if (G[k][j] == INF) continue;
        int nw = G[i][k] + G[k][j];
        if (nw < G[i][j]) G[i][j] = G[j][i] = nw;
      }
    }
  }
}

int find_min(v2i &G, vb &F, size_t s, size_t ns) {
  int res = INF;
  for (size_t i = 0; i < G.size(); ++i) {
    if (F[i] || i == ns) {
      res = min(res, G[i][s]);
    }
  }
  return res;
}

int solve(v2i &G, vb &F) {
  int cost = INF;
  int res = 0;
  for (size_t i = 0; i < G.size(); ++i) {
    if (F[i]) continue;
    int new_cost = 0;
    for (size_t j = 0; j < G.size(); ++j) {
      if (F[j] || i == j) continue;
      new_cost = max(new_cost, find_min(G, F, j, i));
    }
    if (new_cost < cost) {
      cost = new_cost;
      res = i;
    }
  }
  return res + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, f, n, a, b, w;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> f >> n;
    vb F(n);
    while (f--) {
      cin >> a;
      --a;
      F[a] = true;
    }
    cin.ignore();
    v2i G(n, vi(n, INF));
    string line;
    while (true) {
      getline(cin, line);
      if (line.empty()) break;
      stringstream ss(line);
      ss >> a >> b >> w;
      --a, --b;
      G[a][b] = w;
      G[b][a] = w;
    }
    floyd(G);
    if (i) printf("\n");
    printf("%d\n", solve(G, F));
  }
  return 0;
}
