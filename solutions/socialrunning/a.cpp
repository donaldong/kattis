/**
 * @date        2022-03-26
 * @tags        implementation
 * @difficulty  1400
 */
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int N;
  cin >> N;
  vector<int> D(N);
  for (int& d : D) cin >> d;

  auto calc = [&](int s) {
    unordered_map<int,vector<int>> T;
    vector<bool> vis(N, false);
    queue<tuple<int,int,int>> q;
    q.emplace(s, N, 0), vis[s] = true;
    while (!q.empty()) {
      auto [i, k, t] = q.front(); q.pop();
      T[t].push_back(i);
      int j = (i+1)%N;
      if (!vis[j]) vis[j] = true, q.emplace(j, N, t+1);
      if (k-1) q.emplace(j, k-1, t+1);
    }
    int res = 0;
    for (auto& [t, g] : T) {
      if (g.size() > 1) continue;
      res += D[g[0]];
    }
    return res;
  };

  int res = INT_MAX;
  for (int i = 0; i < N; ++i) res = min(res, calc(i));
  cout << res << endl;
  return 0;
}
