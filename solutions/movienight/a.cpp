/**
 * @date        2023-02-06
 * @tags        graph, cycle, counting
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int MOD = 1e9+7;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<int> G(n), col(n, 0);
  vector<vector<int>> rG(n);
  vector<int> cycle_group(n, -1);
  for (int i = 0; i < n; ++i) {
    auto& j = G[i];
    cin >> j;
    --j;
    rG[j].push_back(i);
  }

  vector<ll> groups(n, 0);
  vector<int> path, cycles;
  function<ll(int)> dfs2 = [&](int i) {
    ll res = 1;
    for (int j : rG[i]) res = (res*(dfs2(j)+1))%MOD;
    return res;
  };

  function<void(int)> dfs = [&](int i) {
    if (col[i] == 2) return;
    if (col[i] == 1) {
      for (int p = path.size()-1; p >= 0; --p) {
        int j = path[p];
        cycle_group[j] = i;
        if (j == i) break;
      }
      groups[i] = 1;
      return;
    }
    path.push_back(i);
    col[i] = 1;
    int j = G[i];
    dfs(j);
    if (cycle_group[j] >= 0 && cycle_group[i] < 0) {
      auto& res = groups[cycle_group[j]];
      res = (res*(dfs2(i)+1))%MOD;
    }
    col[i] = 2;
    path.pop_back();
  };
  for (int i = 0; i < n; ++i) dfs(i);
  ll res = 1;
  for (auto group : groups) if (group) res = (res*(group+1))%MOD;
  cout << (res-1+MOD)%MOD << endl;
  return 0;
}
