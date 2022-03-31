/**
 * @date        2022-03-30
 * @tags        shortest path, graph, dp
 * @difficulty  1800
 */
#include <bits/stdc++.h>
using namespace std;
using Adj = vector<vector<pair<int,int>>>;
using Dist = vector<vector<int>>;
using Tuple = tuple<int,int,int>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int c,v,x,s,t,k,q,l;
  cin >> c;
  while (c--) {
    cin >> v;
    Adj Eout(v), Ein(v);
    for (int i = 0; i < v; ++i) {
      cin >> x;
      Eout[i].resize(x);
      for (auto& e : Eout[i]) {
        cin >> e.first >> e.second;
        Ein[e.first].emplace_back(i, e.second);
      }
    }
    auto dijkstra = [&](int s, const Adj& E, int l) {
      Dist D(l+1, vector<int>(v, INT_MAX));
      priority_queue<Tuple,vector<Tuple>,greater<Tuple>> pq;
      D[1][s] = 0, pq.emplace(0, 1, s);
      while (!pq.empty()) {
        auto [d, step, i] = pq.top(); pq.pop();
        if (step >= l || D[step][i] < d) continue;
        for (auto [j, w] : E[i]) {
          if (D[step+1][j] <= d+w) continue;
          D[step+1][j] = d+w, pq.emplace(d+w,step+1,j);
        }
      }
      return D;
    };
    cin >> q;
    while (q--) {
      cin >> s >> t >> k;
      if (s == t) {
        printf("%d\n", k>=1?0:-1);
        continue;
      }
      int res = INT_MAX;
      auto DS = dijkstra(s, Eout, k); // O(E*log(v*k)*2)
      auto DT = dijkstra(t, Ein, k);
      for (int i = 0; i < v; ++i) for (int j = 1; j <= k; ++j) { // O(v*k)
        DS[j][i] = min(DS[j][i], DS[j-1][i]);
        DT[j][i] = min(DT[j][i], DT[j-1][i]);
      }
      for (int i = 1; i < k; ++i) for (int j = 0; j < v; ++j) { // O(v*k)
        int ds = DS[i][j], dt = DT[k-i+1][j];
        if (ds == INT_MAX || dt == INT_MAX) continue;
        res = min(res, ds+dt);
      }
      printf("%d\n", res == INT_MAX ? -1 : res);
    }
    printf("\n");
  }
  return 0;
}
