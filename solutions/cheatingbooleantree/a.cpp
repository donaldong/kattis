/**
 * @date        2023-01-17
 * @tags        graph, tree, dp
 * @difficulty  1500
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int tc, t = 1;
  cin >> tc;
  while (tc--) {
    int m, v;
    cin >> m >> v;
    vector<int> gate(m+1, -1), V(m+1, -1), C(m+1, -1);
    vector<vector<int>> DP(m+1, vector<int>(2, -1));
    {
      int i = 1;
      for (; i <= (m-1)/2; ++i) cin >> gate[i] >> C[i];
      for (; i <= m; ++i) cin >> V[i];
    }
    function<int(int,int)> dfs = [&](int i, int v) {
      if (gate[i] < 0) return V[i] == v ? 0 : INT_MAX;
      auto& res = DP[i][v];
      if (res >= 0) return res;
      if (V[i] == v) return res = 0;
      res = INT_MAX;
      auto update_res = [&](int v1, int v2, int g) {
        int l = dfs(2*i, v1), r = dfs(2*i+1, v2);
        if (l != INT_MAX  && r != INT_MAX) res = min(res, l+r+(g==gate[i]?0:1));
      };
      if (gate[i] || C[i]) { // AND
        if (v) update_res(1,1,1);
        else update_res(1,0,1), update_res(0,1,1), update_res(0,0,1);
      }
      if (!gate[i] || C[i]) { // OR
        if (v) update_res(1,0,0), update_res(0,1,0), update_res(1,1,0);
        else update_res(0,0,0);
      }
      return res;
    };
    int res = dfs(1, v);
    cout << "Case #" << t++ << ": ";
    if (res == INT_MAX) cout << "IMPOSSIBLE\n";
    else cout << res << '\n';
  }
  return 0;
}
