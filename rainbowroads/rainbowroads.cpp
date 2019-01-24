#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;

v3i G;
vb good;
v2b stop;

int dfs(int a, int b) {
  int c;
  int res = 1;
  stack<tuple<int, int>> S;
  S.emplace(a, b);
  good[b] = false;

  while (!S.empty()) {
    tie(a, b) = S.top(); S.pop();
#ifdef DEBUG
    printf("%d => %d\n", a + 1, b + 1);
#endif
    for (int i = 0; i < G[b].size(); ++i) {
      c = G[b][i][0];
      if (c != a) {
        if (stop[b][i]) continue;
        if (!good[c]) return G.size();
        good[c] = false;
        ++res;
        S.emplace(b, c);
      }
    }
  }
  return res;
}

int solve() {
  int n = G.size();
  for (size_t k = 0; k < G.size(); ++k) {
    stop[k] = vb(G[k].size(), false);
    for (size_t i = 1; i < G[k].size(); ++i) for (size_t j = 0; j < i; ++j) {
      if (G[k][i][1] == G[k][j][1]) {
        stop[k][i] = stop[k][j] = true;
      }
    }
  }
  for (size_t i = 0; i < stop.size(); ++i) {
    for (size_t j = 0; j < stop[i].size(); ++j) {
      if (!stop[i][j]) continue;
      n -= dfs(i, G[i][j][0]);
      if (n <= 0) return 0;
    }
  }
  return n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a, b, c;
  cin >> n;
  G.resize(n);
  stop.resize(n);
  good.assign(n, true);

  for (int i = 1; i < n; ++i) {
    cin >> a >> b >> c;
    --a, --b;
    G[a].push_back({b, c}); G[b].push_back({a, c});
  }

  n = solve();
  printf("%d\n", n);
  if (n) for (int i = 0; i < good.size(); ++i) {
    if (good[i]) printf("%d\n", i + 1);
  }
  cout << flush;

  return 0;
}
