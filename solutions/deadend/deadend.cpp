#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> v2i;

vector<tuple<int, int>> res;
vi vis, deg;
v2i G;

void mark(int p, int n) {
  vis[n] = 1;
  for (int nn : G[n]) if (!vis[nn]) mark(n, nn);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m, a, b;
  cin >> n >> m;

  deg.assign(n, 0), G.resize(n);
  for (int i = 0; i < m; ++i) {
    cin >> a >> b, --a, --b;
    G[a].push_back(b), G[b].push_back(a);
    ++deg[a], ++deg[b];
  }

  queue<int> Q;
  for (int i = 0; i < n; ++i) if (deg[i] == 1) Q.push(i);
  while (!Q.empty()) {
    a = Q.front(), Q.pop();
    if (deg[a]) --deg[a];
    for (int b : G[a]) {
      if (!deg[b]) continue;
      --deg[b];
      if (deg[b] == 1) Q.push(b);
    }
  }

  vis.assign(n, 0);
  for (int i = 0; i < n; ++i) if (deg[i] > 1) {
    for (int j : G[i]) if (!deg[j]) mark(-1, j), res.emplace_back(i, j);
  }
  for (int i = 0; i < n; ++i) if (G[i].size() == 1 && !vis[i]) {
    res.emplace_back(i, G[i][0]);
  }

  sort(res.begin(), res.end());
  printf("%lu\n", res.size());
  for (auto &t : res) printf("%d %d\n", get<0>(t) + 1, get<1>(t) + 1);
  return 0;
}
