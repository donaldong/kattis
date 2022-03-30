/**
 * @date        2022-03-30
 * @tags        graph, shortest path, greedy
 * @difficulty  1700
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pair = pair<ll, int>;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int v,e,c,k,m,a,b,w;
  cin >> v >> e >> c >> k >> m;
  vector<vector<pair<int,int>>> adj(v);
  while (e--) {
    cin >> a >> b >> w;
    --a, --b;
    adj[a].emplace_back(b, w), adj[b].emplace_back(a, w);
  }
  vector<ll> dist(v, LLONG_MAX);
  priority_queue<Pair,vector<Pair>,greater<Pair>> pq;
  dist[0] = 0, pq.emplace(0, 0);
  while (!pq.empty()) {
    auto [d1, i] = pq.top(); pq.pop();
    if (dist[i] < d1) continue;
    for (auto [j, w] : adj[i]) {
      ll d2 = w + d1;
      if (dist[j] <= d2) continue;
      dist[j] = d2, pq.emplace(d2, j);
    }
  }
  vector<ll> C;
  C.reserve(c);
  for (int i = 0; i < c; ++i) {
    cin >> a;
    --a;
    if (dist[a] != LLONG_MAX) C.push_back(2*dist[a]);
  }
  sort(C.begin(), C.end());
  if (k > C.size() && m > C.size()) {
    cout << -1 << endl;
    return 0;
  }
  ll res = 0;
  int size = C.size();
  for (int i = 0; i < min({k, m, size}); ++i) res = max(res, C[i]);
  cout << res << endl;
  return 0;
}
