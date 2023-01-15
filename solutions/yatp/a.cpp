/**
 * @date        2023-01-14
 * @tags        graph, centroid decomposition, slope trick, binary search
 * @difficulty  2100
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using edge = pair<int,int>; // <to, weight>
struct line {
  int a; ll b;
  ll y(ll x) const { return a*x+b; }
  int intercept(const line& other) const {
    if (y(INT_MAX) <= other.y(INT_MAX)) return -1;
    ll lo = 0, hi = INT_MAX;
    while (lo <= hi) {
      ll x = (lo+hi)/2;
      if (y(x) > other.y(x)) hi = x-1;
      else lo = x+1;
    }
    return hi;
  }
};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL); // Fast IO
  int n;
  cin >> n;
  vector<int> P(n); // penalty
  for (auto& p : P) cin >> p;
  vector<vector<edge>> G(n); // graph
  for (int _ = 1, i, j, w; _ < n; ++_) {
    cin >> i >> j >> w;
    --i, --j;
    G[i].emplace_back(j, w), G[j].emplace_back(i, w);
  }

  vector<ll> cost(n);
  vector<bool> vis(n, false);
  vector<int> size(n, 0);
  for (int i = 0; i < n; ++i) cost[i] = (ll)P[i]*P[i];

  function<int(int, int)> update_size = [&](int par, int i) {
    if (vis[i]) return size[i] = 0;
    size[i] = 1;
    for (auto [j,_] : G[i]) {
      if (j == par) continue;
      size[i] += update_size(i, j);
    }
    return size[i];
  };

  vector<tuple<int,int,ll>> stack;
  stack.reserve(n);
  function<int(int)> find_centroid = [&](int c) {
    int bestSize = size[c], tot = size[c];
    stack.emplace_back(-1, c, 0);
    while (!stack.empty()) {
      auto [par, i, dist] = stack.back();
      stack.pop_back();
      int k = tot-size[i];
      for (auto [j,w] : G[i]) {
        if (j == par || vis[j]) continue;
        k = max(k, size[j]);
        stack.emplace_back(i, j, dist+w);
      }
      if (k >= bestSize) continue;
      bestSize = k, c = i;
    }
    return c;
  };

  vector<line> L;
  vector<pair<int,int>> T; // thresholds
  L.reserve(n), T.reserve(n);
  function<void(int)> update_cost = [&](int c) {
    L.clear(), T.clear();
    stack.emplace_back(-1, c, 0);
    while (!stack.empty()) {
      auto [par, i, dist] = stack.back();
      stack.pop_back();
      L.push_back({.a = P[i], .b = dist});
      for (auto [j,w] : G[i]) {
        if (j == par || vis[j]) continue;
        stack.emplace_back(i, j, dist+w);
      }
    }
    sort(L.begin(), L.end(), [](line& x, line& y) {
      if (x.b != y.b) return x.b<y.b;
      return x.a<y.a;
    });
    stack.emplace_back(-1, c, 0), T.emplace_back(0, 0);
    for (int j = 1; j < L.size(); ++j) {
      auto [x0, i] = T.back();
      auto x1 = L[i].intercept(L[j]);
      if (x1 < 0) continue;
      if (x1 < x0) {
        T.pop_back(), --j; // process again
        continue;
      }
      if (x1 == x0) {
        if (L[j].a < L[i].a) T.back().second = j; // overwrite with better line
      } else T.emplace_back(x1, j); // add a new line
    }
    while (!stack.empty()) {
      auto [par, i, dist] = stack.back();
      stack.pop_back();
      auto itr = prev(upper_bound(T.begin(), T.end(), make_pair(P[i], 0)));
      cost[i] = min(cost[i], dist+L[itr->second].y(P[i]));
      for (auto [j,w] : G[i]) {
        if (j == par || vis[j]) continue;
        stack.emplace_back(i, j, dist+w);
      }
    }
  };

  function<void(int)> dfs = [&](int i) {
    if (vis[i]) return;
    update_size(-1, i);
    int c = find_centroid(i);
    vis[c] = true;
    update_cost(c);
    for (auto [j,_] : G[c]) dfs(j);
  };

  dfs(0);
  cout << accumulate(cost.begin(), cost.end(), 0LL) << endl;
  return 0;
}
