/**
 * @date        2023-01-16
 * @tags        graph, all pair shortest path
 * @difficulty  1750
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct lecture { int c,s,e; };
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int t,c,l;
  cin >> t;
  while (t--) {
    cin >> c >> l;
    vector<vector<ll>> dist(c, vector<ll>(c, LLONG_MAX));
    for (int i = 0; i < c; ++i) dist[i][i] = 0;
    for (int _ = c*(c-1)/2, i, j, t; _ > 0; --_) {
      cin >> i >> j >> t;
      dist[i][j] = dist[j][i] = t;
    }
    for (int k = 0; k < c; ++k) { // Floyd-Warshall 
      for (int i = 0; i < c; ++i) {
        if (dist[i][k] == LLONG_MAX) continue;
        for (int j = 0; j < c; ++j) {
          if (dist[k][j] == LLONG_MAX) continue;
          dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
        }
      }
    }
    vector<lecture> L(l);
    vector<int> DP(l, -1);
    vector<vector<int>> G(l);
    for (auto& l : L) cin >> l.c>> l.s >> l.e;
    for (int i = 0; i < l; ++i) for (int j = 0; j < l; ++j) {
      if (L[i].e + dist[L[i].c][L[j].c] > L[j].s) continue;
      G[i].push_back(j);
    }
    function<int(int)> dfs = [&](int i) {
      auto& res = DP[i];
      if (res >= 0) return res;
      res = 1;
      for (int j : G[i]) res = max(res, dfs(j)+1);
      return res;
    };
    int res = 0;
    for (int i = 0; i < l; ++i) res = max(res, dfs(i));
    cout << res << '\n';
  }
  return 0;
}
