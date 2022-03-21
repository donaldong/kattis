#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using v2i = vector<vi>;
using v3i = vector<v2i>;
using vb = vector<bool>;
using v2b = vector<vb>;

v2i G;
unordered_map<int, v2i> C;
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
    for (size_t i = 0; i < G[b].size(); ++i) {
      c = G[b][i];
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
  v2i srcs;
  srcs.reserve(n);
  for (auto &c : C) {
    auto &E = c.second;
    unordered_map<int, vi> nodes;
    for (size_t j = 0; j < E.size(); ++j) {
      nodes[E[j][0]].push_back(E[j][1]);
      nodes[E[j][2]].push_back(E[j][3]);
    }
    for (auto &p : nodes) {
      if (p.second.size() < 2) continue;
      int j = p.first;
      for (int k : p.second) {
#ifdef DEBUG
        printf("stop: %d => %d\n", j + 1, k + 1);
#endif
        stop[j][k] = true;
        srcs.push_back({j, G[j][k]});
      }
    }
  }
  for (auto &p : srcs) {
    n -= dfs(p[0], p[1]);
    if (n <= 0) return 0;
  }
  return n;
}

int main() {
  ios::sync_with_stdio(0);

  int n, a, b, c;
  scanf("%d", &n);
  G.resize(n), stop.resize(n);
  good.assign(n, true);

  for (int i = 1; i < n; ++i) {
    scanf("%d %d %d", &a, &b, &c);
    --a, --b, --c;
    C[c].push_back({a, (int) G[a].size(), b, (int) G[b].size()});
    G[a].push_back(b); G[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    stop[i] = vb(G[i].size(), false);
  }

  n = solve();
  printf("%d\n", n);
  if (n) for (int i = 0; i < good.size(); ++i) {
    if (good[i]) printf("%d\n", i + 1);
  }
  cout << flush;

  return 0;
}
